#include "qt_headers/main_window/mainwindow.h"
#include "../../forms/ui_mainwindow.h"

#include <QFile>
#include <QLabel>

MainWindow::MainWindow(DmxGateway& dmx_gtw, QWidget *parent) :
    dmx_gateway_(dmx_gtw),
    QMainWindow(parent),
    ui_(new Ui::main_window_)
{
    dmx_fixture_array_ = new FixtureArray(dmx_gateway_);
    dmx_patcher_ = new Patcher(dmx_gateway_.GetAmountUniv(), *dmx_fixture_array_, std::vector<std::vector<bool>> (dmx_gateway_.GetAmountUniv(), std::vector<bool>(512, false)));

    ui_->setupUi(this);
    ui_->fixture_display_->setFixtureArray(dmx_fixture_array_);

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
    delete dmx_patcher_;
}

void MainWindow::SetupModalWindows() {
    qdial_patching_ = new QDialogPatching(dmx_patcher_, this);
    qdial_patching_->setWindowTitle("Fixture patching");
    qdial_patching_->Setup();
}

void MainWindow::SetupConnections() {
    bool bok = connect(ui_->btn_patching_, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    qDebug() << bok;
    bok = connect(ui_->fixture_display_, &FixtureDisplay::FixtureChoosen, ui_->fixture_properties_, &FixtureProperties::FixtureChoosen);
    qDebug() << bok;
}



