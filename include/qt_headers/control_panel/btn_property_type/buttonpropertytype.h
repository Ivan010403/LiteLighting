#ifndef BUTTONPROPERTYTYPE_H
#define BUTTONPROPERTYTYPE_H

#include <QPushButton>
#include <QPainter>

#include "light_headers/CustomTypeEnum.h"
#include "light_headers/Fixture.h"
#include "light_headers/programming_command/abstractcommand.h"

class ButtonPropertyType : public QPushButton {
Q_OBJECT

public:
    explicit ButtonPropertyType(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type, QWidget* parent = nullptr);

    ~ButtonPropertyType() = default;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void SetupUi();

    AbstractCommand** main_command_;
    Fixture** selected_fixture_;
    const PropertyType property_type_;
};

#endif // BUTTONPROPERTYTYPE_H
