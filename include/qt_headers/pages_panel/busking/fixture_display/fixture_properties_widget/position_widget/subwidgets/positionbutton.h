#ifndef POSITIONBUTTON_H
#define POSITIONBUTTON_H
#include <QPushButton>
#include <QString>
#include <QPainter>

class PositionButton : public QWidget {
    Q_OBJECT
public:
    explicit PositionButton (const QString& name, QWidget *parent = nullptr) : text_(name), QWidget(parent) {
        closed_icon_.load("/home/ivan/LiteLighting/res/closed.jpg");
        opened_icon_.load("/home/ivan/LiteLighting/res/opened.png");

        setFixedSize(110, 50);
    }

    ~PositionButton() = default;

protected:
    void paintEvent(QPaintEvent* event) {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);


        const int w = width();
        const int h = height();
        // const int centerX = w / 2;
        // const int centerY = h / 2;
        // const int radius = qMin(w, h) / 3;

        painter.setPen(main_border_color_);
        painter.drawRect(0, 0, w, h);

        painter.drawRect(50, 10, w - 60, h - 20);

        painter.drawPixmap(10, 10, 30, 30, closed_icon_);

        painter.drawText(60, 15, 30, 20, Qt::AlignCenter, "Follow");


    }
private:
    const QColor main_bckgrnd_clr_ = QColor(200, 0, 0); // maybe static constexpr?
    const QColor btn_bckgrnd_clr_ = QColor(200, 0, 0); // maybe static constexpr?

    const QColor main_border_color_ = QColor(200, 0, 0);
    const QColor btn_border_color_ = QColor(200, 0, 0);


    QPixmap closed_icon_;
    QPixmap opened_icon_;

    QFont font;
    const QString text_;

};

#endif // POSITIONBUTTON_H
