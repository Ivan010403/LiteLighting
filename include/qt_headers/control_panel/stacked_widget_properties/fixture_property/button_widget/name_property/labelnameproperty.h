#ifndef LABELNAMEPROPERTY_H
#define LABELNAMEPROPERTY_H

#include <QLabel>
#include <QPainter>

class LabelNameProperty : public QLabel {
public:
    explicit LabelNameProperty(QString name, QWidget* parent = nullptr) :
        name_(name),
        QLabel(parent) {}

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(painter);
        drawBorder(painter);
        drawText(painter);
    }

    void drawBackground(QPainter& painter) {
        QBrush brush (QColor(29, 33, 34, 180));

        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 5, 5);
    }

    void drawBorder(QPainter& painter) {
        QPen pen(QColor(96, 102, 104));

        pen.setWidth(2);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 5, 5);
    }

    void drawText(QPainter& painter) {
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, name_);
    }

private:
    const QString name_;
};

#endif // LABELNAMEPROPERTY_H
