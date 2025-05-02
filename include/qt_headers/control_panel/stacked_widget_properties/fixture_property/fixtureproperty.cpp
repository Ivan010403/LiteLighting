#include "fixtureproperty.h"

FixtureProperty::FixtureProperty(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent) :
    type_property_(type),
    QWidget(parent)
{
    SetupUi(main_command, selected_fixture);

    if (selected_fixture) {
        SetupConnections();
    }
}

void FixtureProperty::SetupUi(AbstractCommand** main_command, Fixture** selected_fixture) {
    hlayout_main_ = new QHBoxLayout(this);
    hlayout_main_->setContentsMargins(0, 0, 0, 0);
    hlayout_main_->setSpacing(23);

    btn_value_ = new ButtonValue(main_command, selected_fixture, type_property_, this);
    scrl_bar_value_ = new ScrollBarValue(this);

    hlayout_main_->addWidget(btn_value_);
    hlayout_main_->addWidget(scrl_bar_value_);
}

void FixtureProperty::SetupConnections() {
    connect(scrl_bar_value_, &QScrollBar::valueChanged, btn_value_, &ButtonValue::onSliderChanged);
    connect(btn_value_, &ButtonValue::valueChanged, scrl_bar_value_, &QScrollBar::setValue);
}
