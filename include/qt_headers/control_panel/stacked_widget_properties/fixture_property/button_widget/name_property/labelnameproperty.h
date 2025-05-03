#ifndef LABELNAMEPROPERTY_H
#define LABELNAMEPROPERTY_H

#include <QLabel>
#include <QPainter>

class LabelNameProperty : public QLabel {
public:
    explicit LabelNameProperty(QString name, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

    void drawBackground(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);

private:
    const QString name_;
};

#endif // LABELNAMEPROPERTY_H
