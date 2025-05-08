#ifndef LABELNAMEPROPERTY_H
#define LABELNAMEPROPERTY_H

#include <QLabel>
#include <QPainter>

#include "light_headers/CustomTypeEnum.h"

class LabelNameProperty : public QLabel {
public:
    explicit LabelNameProperty(QString name, ChannelType* type = nullptr, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

    void drawBackground(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);

private:
    const QString name_;
    const ChannelType* type_;
};

#endif // LABELNAMEPROPERTY_H
