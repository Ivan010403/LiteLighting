#include "qt_headers/mainwindow.h"

MainWindow::MainWindow(DmxGateway& dmx_gtw, QWidget* parent) :
    dmx_gateway_(dmx_gtw),
    QMainWindow(parent)
{
    dmx_fixture_array_ = new FixtureArrayModel(dmx_gateway_); // снова new! можно через ссылки

    SetupUi();
    showMaximized();

    // REFACTOR!!!!!!!!!!!!!!!!!!!!!!!!
    // ---------------------------------------------------------


    QFile styleFile("../../include/styles/main/main_style.qss"); // разообраться с этим стрёмным путём до файла
    styleFile.open(QFile::ReadOnly);
    setStyleSheet(styleFile.readAll());

    // SetupModalWindows();
    SetupConnections();
}

MainWindow::~MainWindow()
{
    dmx_gateway_.Stop();

    delete dmx_fixture_array_;
}

void MainWindow::SetupUi() {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(1280, 720);
    this->setMinimumSize(QSize(1280, 720));

    central_widget_ = new QWidget(this);
    vlayout_main_ = new QVBoxLayout(central_widget_);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);

    //-----------------------------------------------------------
    hlayout_top_ = new QHBoxLayout();
    hlayout_top_->setContentsMargins(0, 0, 0, 0);
    hlayout_top_->setSpacing(0);

    settings_panel_ = new SettingsPanel(central_widget_);
    middle_panel_ = new MiddlePanel(dmx_fixture_array_, central_widget_);
    pages_panel_ = new PagesPanel(central_widget_);
    hlayout_top_->addWidget(settings_panel_);
    hlayout_top_->addWidget(middle_panel_);
    hlayout_top_->addWidget(pages_panel_);

    hlayout_top_->setStretch(0, 4);
    hlayout_top_->setStretch(1, 81);
    hlayout_top_->setStretch(2, 11);

    vlayout_main_->addLayout(hlayout_top_);
    //-----------------------------------------------------------
    control_panel_ = new ControlPanel(central_widget_);

    vlayout_main_->addWidget(control_panel_);

    vlayout_main_->setStretch(0,73);
    vlayout_main_->setStretch(1,40);

    this->setCentralWidget(central_widget_);
}

void MainWindow::SetupConnections() {
    connect(pages_panel_, &PagesPanel::showProgramming, middle_panel_, &MiddlePanel::showProgramming);
    connect(pages_panel_, &PagesPanel::showExecButtons, middle_panel_, &MiddlePanel::showExecButtons);
    connect(pages_panel_, &PagesPanel::showBusking, middle_panel_, &MiddlePanel::showBusking);
    connect(pages_panel_, &PagesPanel::showPatchSheet, middle_panel_, &MiddlePanel::showPatchSheet);
    connect(pages_panel_, &PagesPanel::showSettings, middle_panel_, &MiddlePanel::showSettings);
    // connect(ui_->btn_patching_, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    // connect(ui_->fixture_display_, &FixtureDisplay::FixtureChoosen, ui_->fixture_properties_, &FixtureProperties::FixtureChoosen);
}

// void MainWindow::SetupModalWindows() {
//     // qdial_patching_ = new QDialogPatching(dmx_fixture_array_, this);
// }

