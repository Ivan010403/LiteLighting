#include "qt_headers/mainwindow.h"

MainWindow::MainWindow(DmxGateway& dmx_gtw, QWidget* parent) :
    dmx_gateway_(dmx_gtw),
    QMainWindow(parent)
{
    selected_fixture_ = new Fixture*;
    main_command_ = new AbstractCommand*;

    *selected_fixture_ = nullptr;
    *main_command_ = new AbstractCommand();

    dmx_fixture_array_ = new FixtureArrayModel(selected_fixture_, dmx_gateway_);

    SetupUi();
    showMaximized();

    QFile styleFile("../../include/styles/main/main_style.qss"); // разообраться с этим стрёмным путём до файла
    styleFile.open(QFile::ReadOnly);
    setStyleSheet(styleFile.readAll());

    SetupConnections();
}

MainWindow::~MainWindow()
{
    dmx_gateway_.Stop();

    delete dmx_fixture_array_;
    delete selected_fixture_;
    delete main_command_;
}

void MainWindow::SetupUi() {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(1280, 720);
    this->setMinimumSize(QSize(1280, 720));

    central_widget_ = new QWidget(this);
    vlayout_main_ = new QVBoxLayout(central_widget_);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);


    hlayout_top_ = new QHBoxLayout();
    hlayout_top_->setContentsMargins(0, 0, 0, 0);
    hlayout_top_->setSpacing(0);

    settings_panel_ = new SettingsPanel(central_widget_);
    middle_panel_ = new MiddlePanel(main_command_, selected_fixture_, dmx_fixture_array_, central_widget_);
    pages_panel_ = new PagesPanel(central_widget_);
    hlayout_top_->addWidget(settings_panel_);
    hlayout_top_->addWidget(middle_panel_);
    hlayout_top_->addWidget(pages_panel_);

    hlayout_top_->setStretch(0, 20);
    hlayout_top_->setStretch(1, 389);
    hlayout_top_->setStretch(2, 55);

    vlayout_main_->addLayout(hlayout_top_);


    control_panel_ = new ControlPanel(main_command_, selected_fixture_, central_widget_);

    vlayout_main_->addWidget(control_panel_);

    vlayout_main_->setStretch(0,75);
    vlayout_main_->setStretch(1,29);

    this->setCentralWidget(central_widget_);
}

void MainWindow::SetupConnections() {
    connect(pages_panel_, &PagesPanel::showProgramming, middle_panel_, &MiddlePanel::showProgramming);
    connect(pages_panel_, &PagesPanel::showBusking, middle_panel_, &MiddlePanel::showBusking);
    connect(pages_panel_, &PagesPanel::showPatchSheet, middle_panel_, &MiddlePanel::showPatchSheet);
    connect(pages_panel_, &PagesPanel::showSettings, middle_panel_, &MiddlePanel::showSettings);
}

