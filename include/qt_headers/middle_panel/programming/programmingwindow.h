#ifndef PROGRAMMINGWINDOW_H
#define PROGRAMMINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QScrollArea>

#include "./scroll_area_widget/scrollareawidget.h"

class ProgrammingWindow : public QWidget {
Q_OBJECT

public:
    explicit ProgrammingWindow(QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~ProgrammingWindow() = default;


private:
    void SetupUi() {
        gridlayout_main_ = new QGridLayout(this);
        gridlayout_main_->setContentsMargins(0, 0, 0, 0);

        scrl_groups_ = new QScrollArea(this);
        cntnt_wdgt_groups_ = new ScrollAreaWidget(ProgrammingType::Group, scrl_groups_->verticalScrollBar());
        scrl_groups_->setWidget(cntnt_wdgt_groups_);

        scrl_default_ = new QScrollArea(this);
        cntnt_wdgt_default_ = new ScrollAreaWidget(ProgrammingType::Default, scrl_default_->verticalScrollBar());
        scrl_default_->setWidget(cntnt_wdgt_default_);

        scrl_positions_ = new QScrollArea(this);
        cntnt_wdgt_positions_ = new ScrollAreaWidget(ProgrammingType::Position, scrl_positions_->verticalScrollBar());
        scrl_positions_->setWidget(cntnt_wdgt_positions_);

        scrl_color_ = new QScrollArea(this);
        cntnt_wdgt_color_ = new ScrollAreaWidget(ProgrammingType::Color, scrl_color_->verticalScrollBar());
        scrl_color_->setWidget(cntnt_wdgt_color_);

        scrl_beam_ = new QScrollArea(this);
        cntnt_wdgt_beam_ = new ScrollAreaWidget(ProgrammingType::Beam, scrl_beam_->verticalScrollBar());
        scrl_beam_->setWidget(cntnt_wdgt_beam_);

        scrl_focus_ = new QScrollArea(this);
        cntnt_wdgt_focus_ = new ScrollAreaWidget(ProgrammingType::Focus, scrl_focus_->verticalScrollBar());
        scrl_focus_->setWidget(cntnt_wdgt_focus_);

        gridlayout_main_->addWidget(scrl_groups_, 0, 0, 1, 2);
        gridlayout_main_->addWidget(scrl_default_, 1, 0, 1, 2);
        gridlayout_main_->addWidget(scrl_positions_, 2, 0, 4, 1);
        gridlayout_main_->addWidget(scrl_color_, 2, 1, 4, 1);
        gridlayout_main_->addWidget(scrl_beam_, 6, 0, 2, 1);
        gridlayout_main_->addWidget(scrl_focus_, 6, 1, 2, 1);

        gridlayout_main_->setRowStretch(0, 1); // авторастяжение
        gridlayout_main_->setRowStretch(1, 1);
        gridlayout_main_->setRowStretch(2, 1);
        gridlayout_main_->setRowStretch(3, 1);
        gridlayout_main_->setRowStretch(4, 1);
        gridlayout_main_->setRowStretch(5, 1);
        gridlayout_main_->setRowStretch(6, 1);
        gridlayout_main_->setRowStretch(7, 1);
    }

    QGridLayout* gridlayout_main_;

    QScrollArea* scrl_groups_;
    ScrollAreaWidget* cntnt_wdgt_groups_;

    QScrollArea* scrl_default_;
    ScrollAreaWidget* cntnt_wdgt_default_;

    QScrollArea* scrl_positions_;
    ScrollAreaWidget* cntnt_wdgt_positions_;

    QScrollArea* scrl_color_;
    ScrollAreaWidget* cntnt_wdgt_color_;

    QScrollArea* scrl_beam_;
    ScrollAreaWidget* cntnt_wdgt_beam_;

    QScrollArea* scrl_focus_;
    ScrollAreaWidget* cntnt_wdgt_focus_;

};

#endif // PROGRAMMINGWINDOW_H
