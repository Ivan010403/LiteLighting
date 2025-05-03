#include "buttonvalueproperty.h"

ButtonValueProperty::ButtonValueProperty(const uint8_t* ptr_value, const bool* flag_command, const bool* flag_fixture, QWidget* parent) :
    ptr_value_(ptr_value),
    flag_command_(flag_command),
    is_fixture_selected_(flag_fixture),
    QPushButton(parent) {}

void ButtonValueProperty::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawBorder(painter);
    drawText(painter);
}

void ButtonValueProperty::drawBackground(QPainter& painter) {
    QBrush brush (QColor(29, 33, 34));

    if ((*is_fixture_selected_) && (*flag_command_)) {
        brush.setColor(QColor(Qt::red));
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 10, 10);
}

void ButtonValueProperty::drawBorder(QPainter& painter) {
    QPen pen(QColor(96, 102, 104));

    if (isDown()) {
        pen.setColor(QColor(118, 156, 227));
    }

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 10, 10);
}

void ButtonValueProperty::drawText(QPainter& painter) {
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, QString::number(*ptr_value_));
}
