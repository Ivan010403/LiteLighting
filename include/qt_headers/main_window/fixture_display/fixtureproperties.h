#ifndef FIXTUREPROPERTIES_H
#define FIXTUREPROPERTIES_H
#include <QFrame>
#include <QSlider>

#include "light_headers/FixtureArray.h"


class FixtureProperties : public QFrame {
Q_OBJECT

public:
    explicit FixtureProperties(QWidget* parent = nullptr) : QFrame(parent) {
        SetupUi();
        // SetupConnections();
    }

    ~FixtureProperties() {}

    void setFixtureArray(FixtureArray* fxt_arr) {
        dmx_fixture_array_ = fxt_arr;
    }

public slots:
    void FixtureChoosen(unsigned int fixture_id) {
        current_fixture_id_ = fixture_id;
    }

private slots:
    void sendData(int value) {
        // if (current_fixture_id_) { // убрать, лишняя проверка
        //     ChangeData(value);
        // }
    }

private:
    void SetupUi() {
        sldr_dimmer_ = new QSlider(Qt::Vertical, this);
        sldr_dimmer_->setGeometry(50,20, 100, 100);
        connect(sldr_dimmer_, &QSlider::valueChanged, this, &FixtureProperties::sendData);
    }

    // void ChangeData(int value) {
    //     dmx_fixture_array_->getFixtureByIndex(0)->ChangeData(0, value);
    // }


    QSlider* sldr_dimmer_;

    unsigned int current_fixture_id_ = 0;

    FixtureArray* dmx_fixture_array_;
};

#endif // FIXTUREPROPERTIES_H
