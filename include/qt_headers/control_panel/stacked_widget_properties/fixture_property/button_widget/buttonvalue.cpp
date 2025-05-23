#include "buttonvalue.h"

#include "light_headers/FixtureGroup.h"

ButtonValue::ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, PropertyType prop_type, QWidget* parent) :
    main_command_(main_command),
    selected_fixture_(selected_fixture),
    type_channel_(type),
    prop_type_(prop_type),
    QWidget(parent)
{
    isFlex_ = type_channel_ == ChannelType::Flex ? true : false;

    SetupUi();
    SetupConnections();
}

void ButtonValue::onSliderChanged(int value) {
    if ((*selected_fixture_) && ((*selected_fixture_)->isHaveChannel(type_channel_)) && type_channel_ != ChannelType::Flex) {
        current_value_ = 255 - value; // заменить 255 на константу
        SendDmxData();
        flag_command_ = true;
        value_property_->update();

        emit ChangingChannel(true);
    }
}

void ButtonValue::onQdialChanged(int value, int type) {
    if (*selected_fixture_) {
        if (type != 0) {
            type_channel_ = static_cast<ChannelType>(type - 1);
            name_property_->update();
        }

        if ((*selected_fixture_)->isHaveChannel(type_channel_)) {
            current_value_ = value; // заменить 255 на константу
            SendDmxData();
            flag_command_ = true;
            value_property_->update();

            emit ChangingChannel(true);
            emit BtnValueChanged(255 - static_cast<int>(current_value_));
        }
    }
}

void ButtonValue::onSelectedCommand() {
    flag_command_ = (*main_command_)->CheckExistingChannel(*selected_fixture_, type_channel_);
    value_property_->update();
    emit ChangingChannel((*main_command_)->CheckExistingProperty(*selected_fixture_, prop_type_));
}

void ButtonValue::onSelectedFixture() {
    flag_fixture = true;
    value_property_->update();
}

void ButtonValue::SetupUi() {
    setFixedSize(300, 90);

    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);

    name_property_ = new LabelNameProperty(ChannelTypeToQString(type_channel_), (type_channel_ == ChannelType::Flex ? &type_channel_ : nullptr), this);
    name_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    value_property_ = new ButtonValueProperty(ptr_value_, ptr_command_, ptr_fixture_, this);
    value_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    vlayout_main_->addWidget(name_property_);
    vlayout_main_->addWidget(value_property_);

    qdial_setter_ = new QDialogSetter(type_channel_, this);
}

void ButtonValue::SendDmxData() {
    (*selected_fixture_)->ChangeData(type_channel_, current_value_);
    (*main_command_)->AddAction(*selected_fixture_, type_channel_, current_value_);
}

void ButtonValue::SetupConnections() {
    connect(&Mediator::instance(), &Mediator::SelectingFixture, this, &ButtonValue::onSelectedFixture);
    connect(&Mediator::instance(), &Mediator::SelectingCommand, this, &ButtonValue::onSelectedCommand);

    connect(value_property_, &ButtonValueProperty::clicked, qdial_setter_, &QDialogSetter::exec);
    connect(qdial_setter_, &QDialogSetter::BtnClicking, this, &ButtonValue::onQdialChanged);
}

