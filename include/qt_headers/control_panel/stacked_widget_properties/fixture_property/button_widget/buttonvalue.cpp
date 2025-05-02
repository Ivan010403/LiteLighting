#include "buttonvalue.h"

ButtonValue::ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent) :
    main_command_(main_command),
    selected_fixture_(selected_fixture),
    type_property_(type),
    QWidget(parent)
{
    SetupUi();
}

void ButtonValue::onSliderChanged(int value) {
    current_value_ = 255 - value; // заменить 255 на константу
    SendDmxData();
    value_property_->setText(QString::number(current_value_));
}

void ButtonValue::SetupUi() {
    setFixedSize(300, 90);

    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);

    name_property_ = new QPushButton(ChannelTypeToQString(type_property_), this);
    name_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    value_property_ = new QPushButton("0", this);
    value_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    vlayout_main_->addWidget(name_property_);
    vlayout_main_->addWidget(value_property_);
}

void ButtonValue::SendDmxData() {
    if (*selected_fixture_) {
        (*selected_fixture_)->ChangeData(type_property_, current_value_);
        (*main_command_)->AddAction(*selected_fixture_, type_property_, current_value_);
    }
}
