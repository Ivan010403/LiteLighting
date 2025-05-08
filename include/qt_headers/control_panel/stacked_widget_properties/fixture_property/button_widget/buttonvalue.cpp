#include "buttonvalue.h"

ButtonValue::ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent) :
    main_command_(main_command),
    selected_fixture_(selected_fixture),
    type_channel_(type),
    QWidget(parent)
{
    SetupUi();

    if (selected_fixture) {
        SetupConnections();
    }
}

void ButtonValue::onSliderChanged(int value) {
    if ((*selected_fixture_) && ((*selected_fixture_)->isHaveChannel(type_channel_))) {
        current_value_ = 255 - value; // заменить 255 на константу
        SendDmxData();
        flag_command_ = true;
        value_property_->update();
        emit ChangingChannel(true);
        emit valueChanged(current_value_);
    }
}

void ButtonValue::onSelectedCommand() {
    flag_command_ = (*main_command_)->CheckExistingChannel(*selected_fixture_, type_channel_);
    value_property_->update();
    emit ChangingChannel(flag_command_);
}

void ButtonValue::onUnselectedCommand() {
    // flag_command_ = false;
    // value_property_->update();
    // emit ChangingChannel(false);
}

void ButtonValue::onSelectedFixture() {
    flag_fixture = true;
    value_property_->update();
}

void ButtonValue::onUnselectedFixture() {
    // flag_fixture = false;
    // value_property_->update();
    // emit ChangingChannel(false);
}

void ButtonValue::SetupUi() {
    setFixedSize(300, 90);

    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);

    name_property_ = new LabelNameProperty(ChannelTypeToQString(type_channel_), this);
    name_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    value_property_ = new ButtonValueProperty(ptr_value_, ptr_command_, ptr_fixture_, this);
    value_property_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    vlayout_main_->addWidget(name_property_);
    vlayout_main_->addWidget(value_property_);

    qdial_setter_ = new QDialogSetter(type_channel_);
}

void ButtonValue::SendDmxData() {
    (*selected_fixture_)->ChangeData(type_channel_, current_value_);
    (*main_command_)->AddAction(*selected_fixture_, type_channel_, current_value_);
}

void ButtonValue::SetupConnections() {
    connect(&Mediator::instance(), &Mediator::SelectingFixture, this, &ButtonValue::onSelectedFixture);
    connect(&Mediator::instance(), &Mediator::UnselectingFixture, this, &ButtonValue::onUnselectedFixture);

    connect(&Mediator::instance(), &Mediator::SelectingCommand, this, &ButtonValue::onSelectedCommand);
    connect(&Mediator::instance(), &Mediator::UnselectingCommand, this, &ButtonValue::onUnselectedCommand);

    connect(value_property_, &ButtonValueProperty::clicked, qdial_setter_, &QDialogSetter::exec);
    connect(qdial_setter_, &QDialogSetter::BtnClicking, this, &ButtonValue::onSliderChanged);
}

