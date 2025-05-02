#ifndef BUTTONVALUEPROPERTY_H
#define BUTTONVALUEPROPERTY_H

#include <QPushButton>
#include <QPainter>

class ButtonValueProperty : public QPushButton {
Q_OBJECT
public:
    explicit ButtonValueProperty(const uint8_t* ptr_value, const bool* flag_command, QWidget* parent = nullptr) :
        ptr_value_(ptr_value),
        flag_command_(flag_command),
        QPushButton(parent) {}

public slots:
    void onSelectedFixture() {
        is_fixture_selected_ = true;
        update();
    }

    void onUnselectedFixture() {
        is_fixture_selected_ = false;
        update();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(painter);
        drawBorder(painter);
        drawText(painter);
    }

private:
    void drawBackground(QPainter& painter) {
        QBrush brush (QColor(29, 33, 34));

        if ((is_fixture_selected_) && (*flag_command_)) {
            brush.setColor(QColor(Qt::red));
        }

        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 10, 10);
    }

    void drawBorder(QPainter& painter) {
        QPen pen(QColor(96, 102, 104));

        if (isDown()) {
            pen.setColor(QColor(118, 156, 227));
        }

        pen.setWidth(2);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 10, 10);
    }

    void drawText(QPainter& painter) {
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, QString::number(*ptr_value_));
    }

    const uint8_t* ptr_value_;
    const bool* flag_command_;

    bool is_fixture_selected_ = false;
};

#endif // BUTTONVALUEPROPERTY_H
