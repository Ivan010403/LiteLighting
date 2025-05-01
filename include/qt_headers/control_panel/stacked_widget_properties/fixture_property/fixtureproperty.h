#ifndef FIXTUREPROPERTY_H
#define FIXTUREPROPERTY_H

#include <QHBoxLayout>

#include "./button_widget/buttonvalue.h"
#include "./scroll_bar_widget/scrollbarvalue.h"

class FixtureProperty : public QWidget {
Q_OBJECT
public:
    explicit FixtureProperty(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent = nullptr) : type_property_(type), QWidget(parent) {
        SetupUi(main_command, selected_fixture);

        if (selected_fixture) {
            SetupConnections();
        }
    }

    ~FixtureProperty() = default;

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture) {
        hlayout_main_ = new QHBoxLayout(this);
        hlayout_main_->setContentsMargins(0, 0, 0, 0);
        hlayout_main_->setSpacing(23);

        btn_value_ = new ButtonValue(main_command, selected_fixture, type_property_, this);
        scrl_bar_value_ = new ScrollBarValue(this);

        hlayout_main_->addWidget(btn_value_);
        hlayout_main_->addWidget(scrl_bar_value_);
    }

    void SetupConnections() {
        connect(scrl_bar_value_, &QScrollBar::valueChanged, btn_value_, &ButtonValue::onSliderChanged);
        connect(btn_value_, &ButtonValue::valueChanged, scrl_bar_value_, &QScrollBar::setValue);
    }

    const ChannelType type_property_; // в button value тоже хранится это. Нужно ли хранить это ещё дополнительно здесь?

    QHBoxLayout* hlayout_main_;
    ButtonValue* btn_value_;
    ScrollBarValue* scrl_bar_value_;
};

#endif // FIXTUREPROPERTY_H
