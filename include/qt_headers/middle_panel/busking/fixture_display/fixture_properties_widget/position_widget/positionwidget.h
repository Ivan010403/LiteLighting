#ifndef POSITIONWIDGET_H
#define POSITIONWIDGET_H
#include <QVBoxLayout>

#include "qt_headers/main_window/fixture_display/fixture_properties_widget/position_widget/subwidgets/followmodebutton.h"
#include "qt_headers/main_window/fixture_display/fixture_properties_widget/position_widget/subwidgets/positionbutton.h"
#include "qt_headers/main_window/fixture_display/fixture_properties_widget/position_widget/subwidgets/positionchart.h"

class PositionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PositionWidget(QWidget *parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~PositionWidget() = default;

private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);

        flw_mode_btn_ = new FollowModeButton(this);

        hlayout_btns_ = new QHBoxLayout();
        tilt_btn_ = new PositionButton("tilt", this);
        main_btn_ = new PositionButton("main", this);
        pan_btn_ = new PositionButton("pan", this);
        hlayout_btns_->addWidget(tilt_btn_);
        hlayout_btns_->addWidget(main_btn_);
        hlayout_btns_->addWidget(pan_btn_);
        hlayout_btns_->setContentsMargins(0, 0, 0, 0);

        pos_chart_widget_ = new PositionChart(this);

        vlayout_main_->addWidget(flw_mode_btn_, 1, Qt::AlignHCenter);
        vlayout_main_->addLayout(hlayout_btns_, Qt::AlignHCenter);
        vlayout_main_->addWidget(pos_chart_widget_, 2, Qt::AlignHCenter);
        vlayout_main_->setContentsMargins(0, 0, 0, 0);
    }

    QVBoxLayout* vlayout_main_;

    FollowModeButton* flw_mode_btn_;

    QHBoxLayout* hlayout_btns_;
    PositionButton* tilt_btn_;
    PositionButton* main_btn_;
    PositionButton* pan_btn_;

    PositionChart* pos_chart_widget_;
};

#endif // POSITIONWIDGET_H
