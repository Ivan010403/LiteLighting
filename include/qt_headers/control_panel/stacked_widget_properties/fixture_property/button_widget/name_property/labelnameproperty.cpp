#include "labelnameproperty.h"

LabelNameProperty::LabelNameProperty(QString name, ChannelType* type, QWidget* parent) :
    name_(name),
    type_(type),
    QLabel(parent) {}

void LabelNameProperty::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawBorder(painter);
    drawText(painter);
}

void LabelNameProperty::drawBackground(QPainter& painter) {
    QBrush brush (QColor(29, 33, 34, 180));

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 5, 5);
}

void LabelNameProperty::drawBorder(QPainter& painter) {
    QPen pen(QColor(96, 102, 104));

    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 5, 5);
}

void LabelNameProperty::drawText(QPainter& painter) {
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, name_ + " " + (type_ ? ChannelTypeToQString(*type_) : ""));
}
