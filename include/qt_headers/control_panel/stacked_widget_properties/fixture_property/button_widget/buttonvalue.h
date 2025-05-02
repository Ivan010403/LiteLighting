#ifndef BUTTONVALUE_H
#define BUTTONVALUE_H

#include <QWidget>
#include <QVBoxLayout>
// #include <QLabel>
#include <QPushButton>

#include "light_headers/CustomTypeEnum.h"
#include "light_headers/Fixture.h"
#include "light_headers/programming_command/abstractcommand.h"

class ButtonValue : public QWidget {
Q_OBJECT
public:
    explicit ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent = nullptr);

    ~ButtonValue() = default;

signals:
    void valueChanged(int value);

public slots:
    void onSliderChanged(int value);

private:
    void SetupUi();

    void SendDmxData();

    AbstractCommand** main_command_;
    Fixture** selected_fixture_;
    const ChannelType type_property_;

    uint8_t current_value_ = 0;

    QVBoxLayout* vlayout_main_;
    QPushButton* name_property_; // не меняю никогда, можно сделать константой
    QPushButton* value_property_;


};

#endif // BUTTONVALUE_H
