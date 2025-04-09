#ifndef EXECBUTTONSWINDOW_H
#define EXECBUTTONSWINDOW_H

#include <QWidget>
#include <QPushButton>

class ExecButtonsWindow : public QWidget {
Q_OBJECT

public:
    explicit ExecButtonsWindow(QWidget* parent = nullptr) : QWidget(parent) {
        test = new QPushButton("exec", this);
    }

    ~ExecButtonsWindow() = default;

    QPushButton* test;
};

#endif // EXECBUTTONSWINDOW_H
