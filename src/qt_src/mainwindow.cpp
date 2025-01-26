#include "qt_headers/mainwindow.h"
#include "../../include/forms/ui_mainwindow.h"
#include <QScreen>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui_;
}


