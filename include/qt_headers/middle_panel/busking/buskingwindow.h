#ifndef BUSKINGWINDOW_H
#define BUSKINGWINDOW_H

#include <QWidget>
#include <QPushButton>

class BuskingWindow : public QWidget {
Q_OBJECT

public:
    explicit BuskingWindow(QWidget* parent = nullptr) : QWidget(parent) {
        test = new QPushButton("busking", this);
    }

    ~BuskingWindow() = default;

    QPushButton* test;
};

#endif // BUSKINGWINDOW_H
