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

void SettingsWindow::SetupUi() {
    hlayout_main_ = new QHBoxLayout(this);
    hlayout_main_->setContentsMargins(20, 0, 20, 0);
    hlayout_main_->setSpacing(20);

    btn_load_showfile_ = new QPushButton("Load show", this);
    btn_save_showfile_ = new QPushButton("Save show", this);

    btn_load_showfile_->setFixedHeight(30);
    btn_save_showfile_->setFixedHeight(30);

    hlayout_main_->addWidget(btn_load_showfile_);
    hlayout_main_->addWidget(btn_save_showfile_);
}

void SettingsWindow::SetupConnections() {
    connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
    connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);
}
