#ifndef FOLLOWMODEBUTTON_H
#define FOLLOWMODEBUTTON_H
#include <QWidget>
#include <QPainter>

class FollowModeButton : public QWidget {
    Q_OBJECT

public:
    explicit FollowModeButton (QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(50, 50);
    }

    ~FollowModeButton() = default;

    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setPen(QPen(QColor(80, 80, 80)));
        painter.drawEllipse(0, 0, 50, 50);
    }
};

#endif // FOLLOWMODEBUTTON_H
