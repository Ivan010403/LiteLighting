#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

#include "light_headers/DmxGateway.h"
#include "light_headers/FixtureArray.h"

#include "qt_headers/settings_panel/settingspanel.h"
#include "qt_headers/middle_panel/middlepanel.h"
#include "qt_headers/pages_panel/pagespanel.h"
#include "qt_headers/control_panel/controlpanel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DmxGateway& dmx_gtw, QWidget* parent = nullptr);
    ~MainWindow();

private:
    void SetupUi();
    // void SetupModalWindows();
    // void SetupConnections();

    DmxGateway& dmx_gateway_; // подумать про константность
    FixtureArrayModel* dmx_fixture_array_;

    QWidget* central_widget_;
    QVBoxLayout* vlayout_main_;

    QHBoxLayout* hlayout_top_;
    SettingsPanel* settings_panel_;
    MiddlePanel* middle_panel_;
    PagesPanel* pages_panel_;

    ControlPanel* control_panel_;
};

#endif // MAINWINDOW_H
