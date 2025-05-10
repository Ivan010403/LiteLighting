#include "buskingview.h"

BuskingView::BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    selected_fixture_(selected_fixture),
    btn_move_(btn_move),
    QWidget(parent) {}

void BuskingView::onBtnAddClicked() {
    if (qvect_fixture_buttons_.size() < dmx_fixture_array_->FixtureAmount()) {
        qvect_fixture_buttons_.push_back(new FixtureButton(dmx_fixture_array_, btn_move_, selected_fixture_, dmx_fixture_array_->GetFixtureByIndex(qvect_fixture_buttons_.size()), this));
        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::GroupChoosen, this, &BuskingView::SelectingByGroup);
        connect(this, &BuskingView::SelectingByGroup, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::SelectedByGroup);

        connect(qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::FixtureChoosen, this, &BuskingView::PressingByFixture);
        connect(this, &BuskingView::PressingByFixture, qvect_fixture_buttons_[qvect_fixture_buttons_.size()-1], &FixtureButton::PressedByFixture);
    }
}
