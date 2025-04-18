#ifndef FIXTUREDISPLAY_H
#define FIXTUREDISPLAY_H
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "light_headers/FixtureArray.h"
#include "qt_headers/main_window/fixture_display/fixture_display_button/fixturebutton.h"

class FixtureDisplay : public QFrame {
Q_OBJECT

public:
    explicit FixtureDisplay(QWidget* parent = nullptr) : QFrame(parent) {
        SetupUi();
        SetupConnections();
    }

    ~FixtureDisplay() {}

    void setFixtureArray(FixtureArrayModel* fxt_arr) {
        dmx_fixture_array_ = fxt_arr;
    }

signals:
    void FixtureChoosen(unsigned int);

private slots:
    void OnBtnAddClicked() {
        if (qvect_fixture_buttons_.size() < dmx_fixture_array_->FixtureAmount()) {
            qvect_fixture_buttons_.push_back(new FixtureButton(btn_move_fixture_, dmx_fixture_array_->GetFixtureIdByIndex(qvect_fixture_buttons_.size()), qframe_display_));

            connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::sendFixtureId, this, &FixtureDisplay::FixtureChoosen);
        }
        // REFACTOR THIS!!!!!!!!
        // стрёмно беру индекс, надо нормально. Придумать как!!!
        // REFACTOR THIS!!!!!!!!
    }

    // void OnBtnMoveClicked() {
    //     // btn_move_fixture_
    //     //connect(test, &QPushButton::clicked, this, &FixtureDisplay::FixtureChoosen);
    // }


private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(0, 0, 0, 0);

        hlayout_btns_ = new QHBoxLayout();
        hlayout_btns_->setSpacing(40);

        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_add_fixture_->setEnabled(true);

        btn_move_fixture_ = new QPushButton("Move fixture", this);
        btn_move_fixture_->setEnabled(true);
        btn_move_fixture_->setCheckable(true);

        hlayout_btns_->addWidget(btn_add_fixture_);
        hlayout_btns_->addWidget(btn_move_fixture_);
        hlayout_btns_->setStretch(0, 1);
        hlayout_btns_->setStretch(1, 1);

        qframe_display_ = new QFrame(this);

        vlayout_main_->addLayout(hlayout_btns_);
        vlayout_main_->addWidget(qframe_display_);
        vlayout_main_->setStretch(0,1);
        vlayout_main_->setStretch(1,4);
    }

    void SetupConnections() {
        connect(btn_add_fixture_, &QPushButton::clicked, this, &FixtureDisplay::OnBtnAddClicked);
        // connect(btn_move_fixture_, &QPushButton::clicked, this, &FixtureDisplay::OnBtnMoveClicked);
    }

    QVBoxLayout* vlayout_main_;
    QHBoxLayout* hlayout_btns_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_move_fixture_;
    QFrame* qframe_display_;

    // QMenu* menu_btn_add_fixture_;
    // QListView* listview_add_fixture_;

    QVector<FixtureButton*> qvect_fixture_buttons_;

    FixtureArrayModel* dmx_fixture_array_;
};

#endif // FIXTUREDISPLAY_H
