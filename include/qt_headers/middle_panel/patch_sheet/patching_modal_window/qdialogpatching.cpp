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

int QDialogPatching::exec() {
    label_patching_->setText("patching");
    linedit_name_->clear();
    linedit_fixture_id_->clear();
    linedit_universe_id_->clear();
    linedit_dmx_address_->clear();
    linedit_channel_amount_->clear();

    return QDialog::exec();
}

void QDialogPatching::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogPatching::OnBtnClicked() {
    dmx_fixture_array_->CreateNewFixture(linedit_fixture_id_->text().toInt(), linedit_universe_id_->text().toInt(),
                                         linedit_dmx_address_->text().toInt(), channel_amount_, linedit_name_->text(), linedit_power_->text().toInt(),
                                         channels);
    qDebug() << "QDialogPatching::OnBtnClicked() --> создание фикстуры с fix_id = " << linedit_fixture_id_->text().toInt();
    emit accept();
}

void QDialogPatching::OnChannelAmountEntered() {
    QString text = linedit_channel_amount_->text();
    int pos = 0;
    int temp = linedit_dmx_address_->text().toInt() + text.toInt();
    if ((validator->validate(text, pos) != QValidator::Acceptable) || (temp > 512)) {
        linedit_channel_amount_->clear();
        return;
    }

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
    label_power_ = new QLabel("power", this);
    label_patching_ = new QLabel("patching", this);


    linedit_name_ = new QLineEdit(this);

    linedit_fixture_id_ = new QLineEdit(this);
    linedit_fixture_id_->setValidator(new QIntValidator(0, 10000, linedit_fixture_id_));

    linedit_universe_id_ = new QLineEdit(this);
    linedit_dmx_address_ = new QLineEdit(this);
    linedit_channel_amount_ = new QLineEdit(this);

    linedit_power_ = new QLineEdit(this);
    linedit_power_->setValidator(new QIntValidator(0, 10000, linedit_power_));

    qcmbox_patching_ = new QComboBox(this);
    for (int i = 0; i < static_cast<int>(ChannelType::Flex); ++i) {
        qcmbox_patching_->addItem(ChannelTypeToQString(static_cast<ChannelType>(i)));
    }

    btn_enter_fixture_ = new QPushButton("Enter fixture", this);
    btn_enter_fixture_->setFixedHeight(30);

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

    gridlayout_main_->addWidget(label_power_, 5, 0);
    gridlayout_main_->addWidget(linedit_power_, 5, 1);

    gridlayout_main_->addWidget(label_patching_, 6, 0);
    gridlayout_main_->addWidget(qcmbox_patching_, 6, 1);

    gridlayout_main_->addWidget(btn_enter_fixture_, 7, 0, 1, 2);

    validator = new QIntValidator(0, 511, this);
}

void QDialogPatching::SetupConnections() {
    connect(btn_enter_fixture_, &QPushButton::clicked, this, &QDialogPatching::OnBtnClicked);
    connect(linedit_channel_amount_, &QLineEdit::editingFinished, this, &QDialogPatching::OnChannelAmountEntered);
    connect(qcmbox_patching_, &QComboBox::activated, this, &QDialogPatching::OnIndexChanged);

    connect(linedit_fixture_id_, &QLineEdit::editingFinished, [=]() {
        while ((dmx_fixture_array_->isExistingFixId(linedit_fixture_id_->text().toInt())) || (linedit_fixture_id_->text().toInt() % 100 == 0)) {
            linedit_fixture_id_->setText(QString::number(linedit_fixture_id_->text().toInt() + 1));
        }
    });

    connect(linedit_dmx_address_, &QLineEdit::editingFinished, [=]() {
        QString text = linedit_dmx_address_->text();
        int pos = 0;
        if (validator->validate(text, pos) != QValidator::Acceptable) {
            linedit_dmx_address_->clear();
            return;
        }
    });

    connect(linedit_universe_id_, &QLineEdit::editingFinished, [=]() {
        QString text = linedit_universe_id_->text();
        int pos = 0;
        if ((validator->validate(text, pos) != QValidator::Acceptable) || (text.toInt() > 10)) {
            linedit_universe_id_->clear();
            return;
        }
    });
}
