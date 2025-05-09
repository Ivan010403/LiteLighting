#ifndef BUSKINGVIEW_H
#define BUSKINGVIEW_H

#include <QWidget>

#include "./fixture_display_button/fixturebutton.h"

class BuskingView : public QWidget {
    Q_OBJECT
public:
    explicit BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent = nullptr) :
        dmx_fixture_array_(dmx_fixture_array),
        selected_fixture_(selected_fixture),
        btn_move_(btn_move),
        QWidget(parent) {}

    ~BuskingView() = default;

signals:
    void SelectingByGroup(int group_id);
    void PressingByFixture(int fix_id);

public slots:
    void onBtnAddClicked() {
        if (qvect_fixture_buttons_.size() < dmx_fixture_array_->FixtureAmount()) {
            qvect_fixture_buttons_.push_back(new FixtureButton(dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByIndex(qvect_fixture_buttons_.size()), this));
            connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::GroupChoosen, this, &BuskingView::SelectingByGroup);
            connect(this, &BuskingView::SelectingByGroup, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::SelectedByGroup);

            connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::FixtureChoosen, this, &BuskingView::PressingByFixture);
            connect(this, &BuskingView::PressingByFixture, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::PressedByFixture);
        }
    }

    void onBtnDelClicked() {

    }

private:
    FixtureArrayModel* dmx_fixture_array_;
    Fixture** selected_fixture_;
    QPushButton* btn_move_;

    QVector <FixtureButton*> qvect_fixture_buttons_;
};

#endif // BUSKINGVIEW_H

// connect(btn_add_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnAddClicked);
// connect(btn_delete_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnDelClicked);
