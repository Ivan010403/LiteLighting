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

public slots:
    void onChangedChannel(bool flag);

protected:
    void paintEvent(QPaintEvent* event) override;

    bool flag_ = false;
};

#endif // BUTTONPROPERTYTYPE_H
