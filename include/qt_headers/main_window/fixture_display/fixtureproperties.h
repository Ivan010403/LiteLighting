#ifndef FIXTUREPROPERTIES_H
#define FIXTUREPROPERTIES_H
#include <QFrame>
#include <QSlider>

#include "light_headers/FixtureArray.h"
#include "qt_headers/main_window/fixture_display/fixture_properties_widget/position_widget/positionwidget.h"


class FixtureProperties : public QFrame {
Q_OBJECT

public:
    explicit FixtureProperties(QWidget* parent = nullptr) : QFrame(parent) {
        SetupUi();
        // SetupConnections();
    }

    ~FixtureProperties() {}

    void setFixtureArray(FixtureArrayModel* fxt_arr) {
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
        hlayout_sldrs_ = new QHBoxLayout(this);
        pos_widget_ = new PositionWidget(this);

        hlayout_sldrs_->addWidget(pos_widget_);
    }

    // void ChangeData(int value) {
    //     dmx_fixture_array_->getFixtureByIndex(0)->ChangeData(0, value);
    // }

    // добавить ещё возможные фигнюшки

    QHBoxLayout* hlayout_sldrs_;
    PositionWidget* pos_widget_;


    unsigned int current_fixture_id_ = 0;

    FixtureArrayModel* dmx_fixture_array_;
};

#endif // FIXTUREPROPERTIES_H
