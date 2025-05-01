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
    explicit ButtonValue(AbstractCommand** main_command, Fixture** selected_fixture, ChannelType type, QWidget* parent = nullptr) :
        main_command_(main_command),
        selected_fixture_(selected_fixture),
        type_property_(type),
        QWidget(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~ButtonValue() = default;

signals:
    void valueChanged(int value);

public slots:
    void onSliderChanged(int value) {
        current_value_ = 255 - value; // заменить 255 на константу
        SendDmxData();
        value_property_->setText(QString::number(current_value_));
    }

private:
    void SetupUi() {
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

    void SetupConnections() {

    }

    void SendDmxData() {
        if (*selected_fixture_) {
            (*selected_fixture_)->ChangeData(type_property_, current_value_);
            (*main_command_)->AddAction(*selected_fixture_, type_property_, current_value_);
        }
    }

    AbstractCommand** main_command_;
    Fixture** selected_fixture_;
    const ChannelType type_property_;

    uint8_t current_value_ = 0;

    QVBoxLayout* vlayout_main_;
    QPushButton* name_property_; // не меняю никогда, можно сделать константой
    QPushButton* value_property_;


};

#endif // BUTTONVALUE_H
