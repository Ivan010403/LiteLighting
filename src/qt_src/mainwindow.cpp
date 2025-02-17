#include "qt_headers/mainwindow.h"
#include "../../include/forms/ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::main_window_)
{
    ui_->setupUi(this);

    // ui_->scrollAreaWidgetContents_3

    QFile styleFile("../../include/styles/main/main_style.qss"); // разообраться с этим стрёмным путём до файла
    styleFile.open(QFile::ReadOnly);
    setStyleSheet(styleFile.readAll());
}

MainWindow::~MainWindow()
{
    delete ui_;
}


