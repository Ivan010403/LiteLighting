#include "stackedwidgetproperty.h"

StackedWidgetProperty::StackedWidgetProperty(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type, QWidget* parent) :
    prop_type_(prop_type),
    QWidget(parent)
{
    SetupUi(main_command, selected_fixture);
}

void StackedWidgetProperty::SetupUi(AbstractCommand** main_command, Fixture** selected_fixture) {
    hlayout_main_ = new QHBoxLayout(this);
    hlayout_main_->setContentsMargins(0, 0, 0, 0);
    hlayout_main_->setSpacing(85);

    int x = 0;
    for (auto var : map_property_to_channel[prop_type_]) {
        if (x < 4) {
            FixtureProperty* temp = new FixtureProperty(main_command, selected_fixture, var, prop_type_,this);
            connect(temp->btn_value_, &ButtonValue::ChangingChannel, this, &StackedWidgetProperty::ChangingChannel);
            hlayout_main_->addWidget(temp);
            ++x;
        }
        else {
            break;
        }
    }

    for (int i = map_property_to_channel[prop_type_].size(); i < 4; ++i) {
        hlayout_main_->addWidget(new FixtureProperty(main_command, selected_fixture, ChannelType::Flex, prop_type_, this));
    }
}
