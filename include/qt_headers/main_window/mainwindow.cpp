#include "qt_headers/main_window/mainwindow.h"
#include "../../forms/ui_mainwindow.h"

#include <QFile>
#include <QLabel>

MainWindow::MainWindow(DmxGateway& dmx_gtw, QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::main_window_),
    dmx_gateway_(dmx_gtw)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    showMaximized();

    // REFACTOR!!!!!!!!!!!!!!!!!!!!!!!!
    dmx_fixture_array_ = new FixtureArrayModel(dmx_gateway_); // снова new! можно через ссылки
    // ---------------------------------------------------------


    ui_->setupUi(this);

    // вот это изменить. Сразу через конструктор передать!
    ui_->fixture_display_->setFixtureArray(dmx_fixture_array_);
    ui_->fixture_properties_->setFixtureArray(dmx_fixture_array_);
    // ---------------------------------------------------------

    QFile styleFile("../../include/styles/main/main_style.qss"); // разообраться с этим стрёмным путём до файла
    styleFile.open(QFile::ReadOnly);
    setStyleSheet(styleFile.readAll());

    SetupModalWindows();
    SetupConnections();
}

MainWindow::~MainWindow()
{
    dmx_gateway_.Stop();

    delete ui_;
    delete dmx_fixture_array_;
}

void MainWindow::SetupModalWindows() {
    qdial_patching_ = new QDialogPatching(dmx_fixture_array_, this);
}

void MainWindow::SetupConnections() {
    connect(ui_->btn_patching_, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui_->fixture_display_, &FixtureDisplay::FixtureChoosen, ui_->fixture_properties_, &FixtureProperties::FixtureChoosen);
}



