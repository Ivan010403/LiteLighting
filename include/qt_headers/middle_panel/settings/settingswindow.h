#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

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

    void onEnteringData();

private:
    void SetupUi();

    void SetupConnections();

    FixtureArrayModel* dmx_fixture_array_;

    QGridLayout* gridlayout_main_;
    QPushButton* btn_load_showfile_;
    QPushButton* btn_save_showfile_;

    QLabel* label_amperage_;
    QLineEdit* line_edit_amperage_;

    QLabel* label_amount_;
    QLineEdit* line_edit_amount_;

    QHBoxLayout* hlayout_patching_;

    QPushButton* btn_setup_electrical_;

    QPixmap pixmap_ = QPixmap(":/photo/C16.png");
};

#endif // SETTINGSWINDOW_H
