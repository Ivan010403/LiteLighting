#ifndef BUTTONPROPERTYTYPE_H
#define BUTTONPROPERTYTYPE_H

#include <QPushButton>
#include <QPainter>

#include "light_headers/CustomTypeEnum.h"

class ButtonPropertyType : public QPushButton {
    Q_OBJECT
public:
    explicit ButtonPropertyType(PropertyType prop_type, QWidget* parent = nullptr);

    ~ButtonPropertyType() = default;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // BUTTONPROPERTYTYPE_H
