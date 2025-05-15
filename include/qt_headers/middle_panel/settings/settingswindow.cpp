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

void SettingsWindow::onEnteringData() {
    QLabel* temp = new QLabel(this);
    temp->setFixedSize(100, 200);
    temp->setPixmap(pixmap_);
    temp->setScaledContents(true);

    QComboBox* cmb_box = new QComboBox(this);
    cmb_box->addItem("1");
    cmb_box->addItem("2");
    cmb_box->addItem("3");

    QVBoxLayout* vlayout = new QVBoxLayout();

    vlayout->addWidget(temp);
    vlayout->addWidget(cmb_box);

    hlayout_patching_->addLayout(vlayout);
}

void SettingsWindow::SetupUi() {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(20, 0, 20, 0);
    gridlayout_main_->setSpacing(20);

    btn_load_showfile_ = new QPushButton("Load show", this);
    btn_save_showfile_ = new QPushButton("Save show", this);

    btn_load_showfile_->setFixedHeight(30);
    btn_save_showfile_->setFixedHeight(30);

    label_amperage_ = new QLabel("Enter amperage", this);
    line_edit_amperage_ = new QLineEdit(this);

    label_amount_ = new QLabel("Enter amount", this);
    line_edit_amount_ = new QLineEdit(this);

    hlayout_patching_ = new QHBoxLayout();

    btn_setup_electrical_ = new QPushButton("Setup", this);

    gridlayout_main_->addWidget(btn_load_showfile_, 0, 0, 1, 1);
    gridlayout_main_->addWidget(btn_save_showfile_, 0, 1, 1, 1);

    gridlayout_main_->addWidget(label_amperage_, 1, 0, 1, 1);
    gridlayout_main_->addWidget(line_edit_amperage_, 2, 0, 1, 1);

    gridlayout_main_->addWidget(label_amount_, 1, 1, 1, 1);
    gridlayout_main_->addWidget(line_edit_amount_, 2, 1, 1, 1);

    gridlayout_main_->addLayout(hlayout_patching_, 3, 0, 1, 2);

    gridlayout_main_->addWidget(btn_setup_electrical_, 4, 0, 1, 2);
}

void SettingsWindow::SetupConnections() {
    connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
    connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);

    connect(line_edit_amount_, &QLineEdit::editingFinished, this, &SettingsWindow::onEnteringData);
}
