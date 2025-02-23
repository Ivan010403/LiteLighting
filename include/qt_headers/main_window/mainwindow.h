#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include "qt_headers/main_window/main_settings/patching_window/qdialogpatching.h"

#include "light_headers/Patcher.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DmxGateway& dmx_gtw, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onButtonClicked() {
        qdial_patching_->show();
        qDebug() << "Кнопка была нажата!";
    }


private:
    void SetupConnections();
    void SetupModalWindows();

    Ui::main_window_ *ui_; // указатель на само окно, которое сгенерированно uic

    QDialogPatching *qdial_patching_;

    DmxGateway& dmx_gateway_;
    FixtureArray* dmx_fixture_array_;
    Patcher* dmx_patcher_;
};

#endif // MAINWINDOW_H
