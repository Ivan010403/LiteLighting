#include "qdialogpatching.h"

QDialogPatching::QDialogPatching(FixtureArrayModel* dmx_fixture_array, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    QDialog(parent)
{
    // m_dialog->setAttribute(Qt::WA_DeleteOnClose, false); // Важно!
    // проверить флаги окна!!!

    SetupUi();
    SetupConnections();
}

QDialogPatching::~QDialogPatching() {
    delete channels; // а что если мувнутся данные и я удалю внутри фикстуры?
}

void QDialogPatching::show() {
    label_patching_->setText("patching");
    linedit_name_->clear();
    linedit_fixture_id_->clear();
    linedit_universe_id_->clear();
    linedit_dmx_address_->clear();
    linedit_channel_amount_->clear();

    QDialog::show();
}

void QDialogPatching::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogPatching::OnBtnClicked() {
    dmx_fixture_array_->CreateNewFixture(linedit_fixture_id_->text().toInt(), linedit_universe_id_->text().toInt(),
                                         linedit_dmx_address_->text().toInt(), channel_amount_, linedit_name_->text().toStdString(),
                                         channels);
    qDebug() << "QDialogPatching::OnBtnClicked() --> создание фикстуры с fix_id = " << linedit_fixture_id_->text().toInt();
    hide();
}

void QDialogPatching::OnChannelAmountEntered() {
    channel_amount_ = linedit_channel_amount_->text().toInt();

    if (channel_amount_ > current_order_channel_) {
        delete[] channels;
        channels = new ChannelType[channel_amount_];
    }

    current_order_channel_ = 0;
}

void QDialogPatching::OnIndexChanged(int index) {
    if (current_order_channel_ < channel_amount_) {
        channels[current_order_channel_] = static_cast<ChannelType>(index);
        ++current_order_channel_;

        if (current_order_channel_ != channel_amount_) {
            label_patching_->setText(QString::number(current_order_channel_ + 1));
        }
        else {
            label_patching_->setText("completed");
        }
    }
}

void QDialogPatching::SetupUi() {
    this->setWindowTitle("Создание новой Fixture");
    this->resize(1280,720);
    this->setMinimumSize(1280,720);

    gridlayout_main_ = new QGridLayout(this);

    label_name_ = new QLabel("name", this);
    label_fixture_id_ = new QLabel("fixture_id", this);
    label_universe_id_ = new QLabel("universe_id", this);
    label_dmx_address_ = new QLabel("dmx_address", this);
    label_channel_amount_ = new QLabel("channel_amount", this);
    label_patching_ = new QLabel("patching", this);

    linedit_name_ = new QLineEdit(this);
    linedit_fixture_id_ = new QLineEdit(this);
    linedit_universe_id_ = new QLineEdit(this);
    linedit_dmx_address_ = new QLineEdit(this);
    linedit_channel_amount_ = new QLineEdit(this);

    // сделать юнифицированно и нормально!
    qcmbox_patching_ = new QComboBox(this);
    qcmbox_patching_->addItem("Dimmer");
    qcmbox_patching_->addItem("R");
    qcmbox_patching_->addItem("G");
    qcmbox_patching_->addItem("B");
    qcmbox_patching_->addItem("Pan");
    qcmbox_patching_->addItem("Tilt");

    btn_enter_fixture_ = new QPushButton("Enter fixture", this);

    gridlayout_main_->addWidget(label_name_, 0, 0);
    gridlayout_main_->addWidget(linedit_name_, 0, 1);

    gridlayout_main_->addWidget(label_fixture_id_, 1, 0);
    gridlayout_main_->addWidget(linedit_fixture_id_, 1, 1);

    gridlayout_main_->addWidget(label_universe_id_, 2, 0);
    gridlayout_main_->addWidget(linedit_universe_id_, 2, 1);

    gridlayout_main_->addWidget(label_dmx_address_, 3, 0);
    gridlayout_main_->addWidget(linedit_dmx_address_, 3, 1);

    gridlayout_main_->addWidget(label_channel_amount_, 4, 0);
    gridlayout_main_->addWidget(linedit_channel_amount_, 4, 1);

    gridlayout_main_->addWidget(label_patching_, 5, 0);
    gridlayout_main_->addWidget(qcmbox_patching_, 5, 1);

    gridlayout_main_->addWidget(btn_enter_fixture_, 6, 0, 1, 2);
}

void QDialogPatching::SetupConnections() {
    connect(btn_enter_fixture_, &QPushButton::clicked, this, &QDialogPatching::OnBtnClicked);
    connect(linedit_channel_amount_, &QLineEdit::editingFinished, this, &QDialogPatching::OnChannelAmountEntered);
    connect(qcmbox_patching_, &QComboBox::activated, this, &QDialogPatching::OnIndexChanged);
}
