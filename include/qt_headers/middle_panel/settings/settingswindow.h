#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include "light_headers/FixtureArray.h"

class SettingsWindow : public QWidget {
Q_OBJECT

public:
    explicit SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) :
        dmx_fixture_array_(dmx_fixture_array),
        QWidget(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~SettingsWindow() = default;

private slots:
    void onLoadClicked() {
        dmx_fixture_array_->LoadDataFromShow();
    }

    void onSaveClicked() {
        dmx_fixture_array_->SaveDataToShow();
    }

private:
    void SetupUi() {
        hlayout_main_ = new QHBoxLayout(this);

        btn_load_showfile_ = new QPushButton("Load show", this);
        btn_save_showfile_ = new QPushButton("Save show", this);

        hlayout_main_->addWidget(btn_load_showfile_);
        hlayout_main_->addWidget(btn_save_showfile_);
    }

    void SetupConnections() {
        connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
        connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);

    }

    FixtureArrayModel* dmx_fixture_array_;

    QHBoxLayout* hlayout_main_;
    QPushButton* btn_load_showfile_;
    QPushButton* btn_save_showfile_;
};

#endif // SETTINGSWINDOW_H
