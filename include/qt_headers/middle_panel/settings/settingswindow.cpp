#include "settingswindow.h"

SettingsWindow::SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    QWidget(parent)
{
    SetupUi();
    SetupConnections();
}

void SettingsWindow::onLoadClicked() {
    QFile file("showfile.json");
    if (!file.open(QIODevice::ReadOnly)) return; // обработать нормально - а что если не открылось?

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject root = doc.object();


    dmx_fixture_array_->LoadDataFromShow(root);

    CommandArray::instance().LoadDataFromShow(root, dmx_fixture_array_);

    emit Mediator::instance().LoadBuskFromShow();
}

void SettingsWindow::onSaveClicked() {
    QJsonObject root;

    dmx_fixture_array_->SaveDataToShow(root);

    CommandArray::instance().SaveDataToShow(root);

    emit Mediator::instance().SaveBuskToShow();

    QFile file("showfile.json");
    if (!file.open(QIODevice::WriteOnly)) { // а что если не открылось?
        qDebug() << "Ошибка открытия файла для записи";
    }

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
}

void SettingsWindow::onEnteringData(int value) {
    for (int i = CircuitBreaker::instance().size(); i < value; ++i) {

        QLabel* temp = new QLabel(this);
        temp->setFixedSize(100, 380);
        temp->setPixmap(pixmap_);
        temp->setScaledContents(true);

        QComboBox* cmb_box = new QComboBox(this);
        cmb_box->setObjectName(QString::number(i));
        cmb_box->setFixedWidth(100);
        cmb_box->addItem("Clear");
        cmb_box->addItem("1st phase");
        cmb_box->addItem("2nd phase");
        cmb_box->addItem("3rd phase");

        QVBoxLayout* vlayout = new QVBoxLayout();
        vlayout->setContentsMargins(0,0,0,0);
        vlayout->setSpacing(0);

        vlayout->addWidget(temp);
        vlayout->addWidget(cmb_box);

        if (hlayout_patching_->count() > 1) {
            QLayoutItem* last = hlayout_patching_->takeAt(hlayout_patching_->count()-1);

            if (last->spacerItem()) delete last->spacerItem();
        }

        if (hlayout_patching_->count() == 0) hlayout_patching_->addStretch();
        hlayout_patching_->addLayout(vlayout);
        hlayout_patching_->addStretch();

        ++CircuitBreaker::instance();
    }
}

void SettingsWindow::onSetupClicked() {
    for (int i = 1; i < hlayout_patching_->count() - 1; ++i) {
        QLayoutItem* item = hlayout_patching_->itemAt(i);

        int phase_number = qobject_cast<QComboBox*>(item->layout()->itemAt(1)->widget())->currentIndex();
        // QString order = item->layout()->itemAt(1)->widget()->objectName();

        CircuitBreaker::instance().AddBreaker(phase_number);
    }

    CircuitBreaker::instance().SetAmperage(spnbox_edit_amperage_->value());
    emit CircuitBreaker::instance().UploadingData();
}

void SettingsWindow::SetupUi() {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(20, 20, 20, 20);
    gridlayout_main_->setSpacing(20);

    btn_load_showfile_ = new QPushButton("Load show", this);
    btn_load_showfile_->setFixedHeight(60);
    btn_load_showfile_->setFixedWidth(600);

    btn_save_showfile_ = new QPushButton("Save show", this);
    btn_save_showfile_->setFixedHeight(60);
    btn_save_showfile_->setFixedWidth(600);


    QVBoxLayout* layout_amperage = new QVBoxLayout();
    layout_amperage->setContentsMargins(0, 0, 0, 0);
    layout_amperage->setSpacing(10);

    label_amperage_ = new QLabel("Enter amperage", this);

    spnbox_edit_amperage_ = new QSpinBox(this);
    spnbox_edit_amperage_->setMaximum(10000);

    layout_amperage->addWidget(label_amperage_, 1, Qt::AlignHCenter);
    layout_amperage->addWidget(spnbox_edit_amperage_, Qt::AlignHCenter);


    QVBoxLayout* layout_amount = new QVBoxLayout();
    layout_amount->setContentsMargins(0, 0, 0, 0);
    layout_amount->setSpacing(10);

    label_amount_ = new QLabel("Enter amount", this);

    spnbox_edit_amount_ = new QSpinBox(this);
    spnbox_edit_amount_->setMaximum(15);

    layout_amount->addWidget(label_amount_, 1, Qt::AlignHCenter);
    layout_amount->addWidget(spnbox_edit_amount_, Qt::AlignHCenter);

    QWidget* cont_patching_ = new QWidget(this);
    cont_patching_->setMinimumHeight(500);

    hlayout_patching_ = new QHBoxLayout(cont_patching_);
    hlayout_patching_->setSpacing(0);
    hlayout_patching_->setContentsMargins(0, 0, 0, 0);


    btn_setup_electrical_ = new QPushButton("Setup", this);
    btn_setup_electrical_->setFixedHeight(30);


    gridlayout_main_->addWidget(btn_load_showfile_, 0, 0, 2, 1, Qt::AlignHCenter);
    gridlayout_main_->addWidget(btn_save_showfile_, 0, 1, 2, 1, Qt::AlignHCenter);

    gridlayout_main_->addLayout(layout_amperage, 2, 0, 1, 1);

    gridlayout_main_->addLayout(layout_amount, 2, 1, 1, 1);

    gridlayout_main_->addWidget(cont_patching_, 3, 0, 1, 2);

    gridlayout_main_->addWidget(btn_setup_electrical_, 4, 0, 1, 2);
}

void SettingsWindow::SetupConnections() {
    connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
    connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);

    connect(spnbox_edit_amount_, &QSpinBox::valueChanged, this, &SettingsWindow::onEnteringData);
    connect(btn_setup_electrical_, &QPushButton::clicked, this, &SettingsWindow::onSetupClicked);

}
