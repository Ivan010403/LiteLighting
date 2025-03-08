#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qt_headers/main_window/main_settings/patching_window/qdialogpatching.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window_;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DmxGateway& dmx_gtw, QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked() {
        qdial_patching_->show();
    }

private:
    void SetupModalWindows();
    void SetupConnections();

    Ui::main_window_ *ui_;

    QDialogPatching *qdial_patching_;

    DmxGateway& dmx_gateway_; // подумать про константность
    FixtureArrayModel* dmx_fixture_array_;
};

#endif // MAINWINDOW_H
