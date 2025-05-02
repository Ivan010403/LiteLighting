#ifndef STACKEDWIDGETPROPERTY_H
#define STACKEDWIDGETPROPERTY_H

#include "./fixture_property/fixtureproperty.h"

class StackedWidgetProperty : public QWidget {
Q_OBJECT

public:
    explicit StackedWidgetProperty(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type, QWidget* parent = nullptr);

    ~StackedWidgetProperty() = default;

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture);

    const PropertyType prop_type_;

    QHBoxLayout* hlayout_main_;
};

#endif // STACKEDWIDGETPROPERTY_H
