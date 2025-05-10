#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include "light_headers/FixtureArray.h"
#include "light_headers/programming_command/CommandArray.h"

class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    explicit SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);
    ~SettingsWindow() = default;

private slots:
    void onLoadClicked();

    void onSaveClicked();

private:
    void SetupUi();

    void SetupConnections();

    FixtureArrayModel* dmx_fixture_array_;

    QHBoxLayout* hlayout_main_;
    QPushButton* btn_load_showfile_;
    QPushButton* btn_save_showfile_;
};

#endif // SETTINGSWINDOW_H
