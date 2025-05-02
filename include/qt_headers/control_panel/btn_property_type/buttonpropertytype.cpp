#include "buttonpropertytype.h"

ButtonPropertyType::ButtonPropertyType(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type, QWidget* parent) :
    main_command_(main_command),
    selected_fixture_(selected_fixture),
    property_type_(prop_type),
    QPushButton(parent)
{
    SetupUi();
}

void ButtonPropertyType::paintEvent(QPaintEvent* event) {
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush = (*main_command_)->CheckExistingProperty(*selected_fixture_, property_type_) ? QBrush(QColor(Qt::red)) : QBrush(QColor(Qt::gray));

    const int min_dimension = qMin(width(), height());
    int square_size = qBound(10,  min_dimension / 5, 100);

    const QRect square_rect(width() - square_size - 5, 5, square_size, square_size);

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(square_rect, 10, 10);
}

void ButtonPropertyType::SetupUi() {
    setText(PropertyTypeToQString(property_type_));
}
