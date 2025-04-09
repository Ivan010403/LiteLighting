#ifndef PROGRAMMINGWINDOW_H
#define PROGRAMMINGWINDOW_H

#include <QWidget>
#include <QPushButton>

class ProgrammingWindow : public QWidget {
Q_OBJECT

public:
    explicit ProgrammingWindow(QWidget* parent = nullptr) : QWidget(parent) {
        test = new QPushButton("progr", this);
    }

    ~ProgrammingWindow() = default;

    QPushButton* test;
};

#endif // PROGRAMMINGWINDOW_H
