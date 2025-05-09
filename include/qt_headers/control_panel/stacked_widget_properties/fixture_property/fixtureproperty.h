#ifndef FIXTUREPROPERTY_H
#define FIXTUREPROPERTY_H

#include <QHBoxLayout>

#include "./button_widget/buttonvalue.h"
#include "./scroll_bar_widget/scrollbarvalue.h"

class FixtureProperty : public QWidget {
public:
    explicit FixtureProperty(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, PropertyType prop_type, QWidget* parent = nullptr);

    ~FixtureProperty() = default;

    ButtonValue* btn_value_;

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type);

    void SetupConnections();

    const ChannelType type_property_; // в button value тоже хранится это. Нужно ли хранить это ещё дополнительно здесь?

    QHBoxLayout* hlayout_main_;
    ScrollBarValue* scrl_bar_value_;
};

#endif // FIXTUREPROPERTY_H
