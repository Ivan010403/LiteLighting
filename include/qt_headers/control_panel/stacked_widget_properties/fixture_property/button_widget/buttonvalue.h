#ifndef BUTTONVALUE_H
#define BUTTONVALUE_H

#include <QWidget>
#include <QVBoxLayout>

#include "light_headers/CustomTypeEnum.h"
#include "light_headers/Fixture.h"
#include "light_headers/programming_command/AbstractCommand.h"
#include "light_headers/Mediator.h"

#include "./name_property/labelnameproperty.h"
#include "./value_property/buttonvalueproperty.h"
#include "./modal_window/qdialogsetter.h"

class ButtonValue : public QWidget {
    Q_OBJECT
public:
    explicit ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent = nullptr);

    ~ButtonValue() = default;

signals:
    void BtnValueChanged(int value);
    void ChangingChannel(bool flag);

public slots:
    void onSliderChanged(int value);

private slots:
    void onQdialChanged(int value, int type);

    void onSelectedCommand();
    void onUnselectedCommand();

    void onSelectedFixture();
    void onUnselectedFixture();

private:
    void SetupUi();

    void SetupConnections();

    void SendDmxData();

    AbstractCommand** main_command_;
    Fixture** selected_fixture_;
    ChannelType type_channel_;
    bool isFlex_;

    uint8_t current_value_ = 0;
    const uint8_t* ptr_value_ = &current_value_;

    bool flag_command_ = false;
    const bool* ptr_command_ = &flag_command_;

    bool flag_fixture = false;
    const bool* ptr_fixture_ = &flag_fixture;

    QVBoxLayout* vlayout_main_;
    LabelNameProperty* name_property_; // не меняю никогда, можно сделать константой
    ButtonValueProperty* value_property_;

    QDialogSetter* qdial_setter_;
};

#endif // BUTTONVALUE_H
