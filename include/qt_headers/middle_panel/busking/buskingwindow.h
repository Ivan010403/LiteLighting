#ifndef BUSKINGWINDOW_H
#define BUSKINGWINDOW_H

#include <QWidget>
#include <QPushButton>

#include "./busking_view/buskingview.h"

class BuskingWindow : public QWidget {
public:
    explicit BuskingWindow(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi(dmx_fixture_array, selected_fixture);
        SetupConnections();
    }

    ~BuskingWindow() = default;


private:
    void SetupUi(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture) {
        gridlayout_main_ = new QGridLayout(this);
        gridlayout_main_->setContentsMargins(0, 0, 0, 0);
        gridlayout_main_->setSpacing(0);

        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_move_fixture_ = new QPushButton("Move fixture", this);
        btn_move_fixture_->setCheckable(true);
        btn_delete_fixture_ = new QPushButton("Delete fixture", this);

        busking_view_ = new BuskingView(dmx_fixture_array, selected_fixture, btn_move_fixture_, this);

        btn_open_bindings_ = new QPushButton("Keyboatd bindings", this);

        gridlayout_main_->addWidget(btn_add_fixture_, 0, 0, 1, 1);
        gridlayout_main_->addWidget(btn_move_fixture_, 0, 1, 1, 1);
        gridlayout_main_->addWidget(btn_delete_fixture_, 0, 2, 1, 1);

        gridlayout_main_->addWidget(busking_view_, 1, 0, 5, 3);
        gridlayout_main_->addWidget(btn_open_bindings_, 6, 0, 1, 3);
    }

    void SetupConnections() {
        connect(btn_add_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnAddClicked);
        connect(btn_delete_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnDelClicked);
    }

    QGridLayout* gridlayout_main_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_move_fixture_;
    QPushButton* btn_delete_fixture_;
    BuskingView* busking_view_;
    QPushButton* btn_open_bindings_;
};

#endif // BUSKINGWINDOW_H
