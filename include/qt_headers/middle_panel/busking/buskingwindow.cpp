#include "buskingwindow.h"

BuskingWindow::BuskingWindow(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QWidget* parent) : QWidget(parent) {
    SetupUi(dmx_fixture_array, selected_fixture);
    SetupConnections();
}

void BuskingWindow::SetupUi(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture) {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(0, 5, 0, 0);
    gridlayout_main_->setSpacing(0);

    btn_add_fixture_ = new QPushButton("Add fixture", this);
    btn_move_fixture_ = new QPushButton("Move fixture", this);
    btn_move_fixture_->setCheckable(true);
    btn_add_socket_ = new QPushButton("Add socket", this);

    btn_add_fixture_->setFixedHeight(30);
    btn_move_fixture_->setFixedHeight(30);
    btn_add_socket_->setFixedHeight(30);

    busking_view_ = new BuskingView(dmx_fixture_array, selected_fixture, btn_move_fixture_, this);

    btn_breaker_ = new BreakerButton(this);

    gridlayout_main_->addWidget(btn_add_fixture_, 0, 1, 1, 1);
    gridlayout_main_->addWidget(btn_move_fixture_, 0, 3, 1, 1);
    gridlayout_main_->addWidget(btn_add_socket_, 0, 5, 1, 1);

    gridlayout_main_->setHorizontalSpacing(20);


    gridlayout_main_->addWidget(busking_view_, 1, 0, 5, 7);

    gridlayout_main_->addWidget(btn_breaker_, 6, 0, 1, 7);
}

void BuskingWindow::SetupConnections() {
    connect(btn_add_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnAddClicked);
    connect(btn_add_socket_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnAddSocket);
}
