#include "buttonpropertytype.h"

ButtonPropertyType::ButtonPropertyType(PropertyType prop_type, QWidget* parent) :
    prop_type_(prop_type),
    QPushButton(PropertyTypeToQString(prop_type), parent) {}


void ButtonPropertyType::onChangedChannel(bool flag) {
    flag_ = flag;
    update();
}

void ButtonPropertyType::paintEvent(QPaintEvent* event) {
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush = flag_ ? QBrush(QColor(255, 0, 0, 128)) : QBrush(QColor(92,92,92));

    const int min_dimension = qMin(width(), height());
    int square_size = qBound(10,  min_dimension / 5, 100);

    const QRect square_rect(width() - square_size - 5, 5, square_size, square_size);

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(square_rect, 10, 10);
}
