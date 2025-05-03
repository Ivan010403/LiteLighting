#include "controlpanel.h"

ControlPanel::ControlPanel(AbstractCommand** main_command, Fixture** selected_fixture, QWidget* parent) : QWidget(parent) {
    SetupUi(main_command, selected_fixture);
    SetupConnections();
}

void ControlPanel::showDimmer() {
    stacked_widget_properties_->setCurrentIndex(0);
}
void ControlPanel::showPosition() {
    stacked_widget_properties_->setCurrentIndex(1);
}
void ControlPanel::showGobo() {
    stacked_widget_properties_->setCurrentIndex(2);
}
void ControlPanel::showColor() {
    stacked_widget_properties_->setCurrentIndex(3);
}
void ControlPanel::showBeam() {
    stacked_widget_properties_->setCurrentIndex(4);
}
void ControlPanel::showFocus() {
    stacked_widget_properties_->setCurrentIndex(5);
}
void ControlPanel::showControl() {
    stacked_widget_properties_->setCurrentIndex(6);
}

void ControlPanel::SetupUi(AbstractCommand** main_command, Fixture** selected_fixture) {
    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(20);

    hlayout_btns_prpts_ = new QHBoxLayout();
    hlayout_btns_prpts_->setContentsMargins(0, 0, 0, 0);
    hlayout_btns_prpts_->setSpacing(5);

    btn_dimmer_ = new ButtonPropertyType(PropertyType::Dimmer, this);
    btn_position_ = new ButtonPropertyType(PropertyType::Position, this);
    btn_gobo_ = new ButtonPropertyType(PropertyType::Gobo, this);
    btn_color_ = new ButtonPropertyType(PropertyType::Color, this);
    btn_beam_ = new ButtonPropertyType(PropertyType::Beam, this);
    btn_focus_ = new ButtonPropertyType(PropertyType::Focus, this);
    btn_control_ = new ButtonPropertyType(PropertyType::Control, this);
    btn_dimmer_->setMinimumHeight(100);
    btn_position_->setMinimumHeight(100);
    btn_gobo_->setMinimumHeight(100);
    btn_color_->setMinimumHeight(100);
    btn_beam_->setMinimumHeight(100);
    btn_focus_->setMinimumHeight(100);
    btn_control_->setMinimumHeight(100);


    hlayout_btns_prpts_->addWidget(btn_dimmer_);
    hlayout_btns_prpts_->addWidget(btn_position_);
    hlayout_btns_prpts_->addWidget(btn_gobo_);
    hlayout_btns_prpts_->addWidget(btn_color_);
    hlayout_btns_prpts_->addWidget(btn_beam_);
    hlayout_btns_prpts_->addWidget(btn_focus_);
    hlayout_btns_prpts_->addWidget(btn_control_);



    stacked_widget_properties_ = new QStackedWidget(this);
    properties_dimmer_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Dimmer, stacked_widget_properties_);
    properties_position_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Position, stacked_widget_properties_);
    properties_gobo_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Gobo, stacked_widget_properties_);
    properties_color_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Color, stacked_widget_properties_);
    properties_beam_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Beam, stacked_widget_properties_);
    properties_focus_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Focus, stacked_widget_properties_);
    properties_control_ = new StackedWidgetProperty(main_command, selected_fixture, PropertyType::Control, stacked_widget_properties_);

    stacked_widget_properties_->addWidget(properties_dimmer_);
    stacked_widget_properties_->addWidget(properties_position_);
    stacked_widget_properties_->addWidget(properties_gobo_);
    stacked_widget_properties_->addWidget(properties_color_);
    stacked_widget_properties_->addWidget(properties_beam_);
    stacked_widget_properties_->addWidget(properties_focus_);
    stacked_widget_properties_->addWidget(properties_control_);


    vlayout_main_->addLayout(hlayout_btns_prpts_);
    vlayout_main_->addWidget(stacked_widget_properties_);
}

void ControlPanel::SetupConnections() {
    connect(btn_dimmer_, &QPushButton::clicked, this, &ControlPanel::showDimmer);
    connect(btn_position_, &QPushButton::clicked, this, &ControlPanel::showPosition);
    connect(btn_gobo_, &QPushButton::clicked, this, &ControlPanel::showGobo);
    connect(btn_color_, &QPushButton::clicked, this, &ControlPanel::showColor);
    connect(btn_beam_, &QPushButton::clicked, this, &ControlPanel::showBeam);
    connect(btn_focus_, &QPushButton::clicked, this, &ControlPanel::showFocus);
    connect(btn_control_, &QPushButton::clicked, this, &ControlPanel::showControl);
}
