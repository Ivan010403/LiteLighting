#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>

class SettingsWindow : public QWidget {
Q_OBJECT

public:
    explicit SettingsWindow(QWidget* parent = nullptr) : QWidget(parent) {
        test = new QPushButton("settings", this);
    }

    ~SettingsWindow() = default;

    QPushButton* test;
};

#endif // SETTINGSWINDOW_H
