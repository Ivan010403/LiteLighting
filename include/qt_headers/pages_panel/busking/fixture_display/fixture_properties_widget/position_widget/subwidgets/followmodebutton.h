#ifndef FOLLOWMODEBUTTON_H
#define FOLLOWMODEBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QPainter>

class FollowModeButton : public QPushButton {
    Q_OBJECT

public:
    explicit FollowModeButton (QWidget *parent = nullptr) : QPushButton(parent) {
        setFixedSize(150, 150);
    }

    ~FollowModeButton() = default;

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        painter.setPen(text_color_);

        font = painter.font();
        font.setPixelSize(13);
        painter.setFont(font);

        sightColor = isDown() ? clicked_color : unclicked_color;

        const int w = width();
        const int h = height();
        const int centerX = w / 2;
        const int centerY = h / 2;
        const int radius = qMin(w, h) / 3;

        painter.drawText(centerX - 30, centerY - 10, 60, 10, Qt::AlignCenter, "Follow");
        painter.drawText(centerX - 30, centerY, 60, 10, Qt::AlignCenter, "mode");

        // Рисуем внешнее кольцо
        painter.setPen(QPen(sightColor, 3));
        painter.drawEllipse(QPoint(centerX, centerY), radius, radius);

        // Рисуем внутреннее кольцо
        painter.setPen(QPen(sightColor, 2));
        painter.drawEllipse(QPoint(centerX, centerY), radius/2, radius/2);
    }

private:
    QFont font;

    QColor sightColor;

    const QColor text_color_ = QColor(255, 255, 255, 80); // maybe static constexpr?
    const QColor clicked_color = QColor(200, 0, 0);
    const QColor unclicked_color = QColor(255, 50, 50);

};

#endif // FOLLOWMODEBUTTON_H
