#ifndef STACKEDWIDGETPROPERTY_H
#define STACKEDWIDGETPROPERTY_H

#include "./fixture_property/fixtureproperty.h"

class StackedWidgetProperty : public QWidget {
Q_OBJECT

public:
    explicit StackedWidgetProperty(AbstractCommand** main_command, Fixture** selected_fixture, PropertyType prop_type, QWidget* parent = nullptr) : prop_type_(prop_type), QWidget(parent) {
        SetupUi(main_command, selected_fixture);
    }

    ~StackedWidgetProperty() = default;

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture) {
        hlayout_main_ = new QHBoxLayout(this);
        hlayout_main_->setContentsMargins(0, 0, 0, 0);
        hlayout_main_->setSpacing(85);

        for (auto var : map_property_to_channel[prop_type_]) {
            hlayout_main_->addWidget(new FixtureProperty(main_command, selected_fixture, var, this));
        }

        for (int i = map_property_to_channel[prop_type_].size(); i < 4; ++i) {
            hlayout_main_->addWidget(new FixtureProperty(nullptr, nullptr, ChannelType::Empty, this));
        }
    }

    const PropertyType prop_type_;

    QHBoxLayout* hlayout_main_;
};

#endif // STACKEDWIDGETPROPERTY_H
