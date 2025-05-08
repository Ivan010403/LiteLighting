#include "programmingwindow.h"

ProgrammingWindow::ProgrammingWindow(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, QWidget* parent) : QWidget(parent) {
    SetupUi(main_command, selected_fixture, dmx_fixture_array);
    SetupConnections();
}

void ProgrammingWindow::onAddedCommand(ProgrammingType type, int number, AbstractCommand* command) {
    switch (type) {
    case ProgrammingType::Position:
        cntnt_wdgt_positions_->GetProgrammButton(number)->SetCommand(command);
        break;
    case ProgrammingType::Color:
        cntnt_wdgt_color_->GetProgrammButton(number)->SetCommand(command);
        break;
    case ProgrammingType::Beam:
        cntnt_wdgt_beam_->GetProgrammButton(number)->SetCommand(command);
        break;
    case ProgrammingType::Focus:
        cntnt_wdgt_focus_->GetProgrammButton(number)->SetCommand(command);
        break;
    default:
        break;
    }
}

void ProgrammingWindow::onDeletingCommand(ProgrammingType type, int number) {
    switch (type) {
    case ProgrammingType::Position:
        cntnt_wdgt_positions_->GetProgrammButton(number)->DeleteCurrentCommand();
        break;
    case ProgrammingType::Color:
        cntnt_wdgt_color_->GetProgrammButton(number)->DeleteCurrentCommand();
        break;
    case ProgrammingType::Beam:
        cntnt_wdgt_beam_->GetProgrammButton(number)->DeleteCurrentCommand();
        break;
    case ProgrammingType::Focus:
        cntnt_wdgt_focus_->GetProgrammButton(number)->DeleteCurrentCommand();
        break;
    default:
        break;
    }
}


void ProgrammingWindow::SetupConnections() {
    connect(&CommandArray::instance(), &CommandArray::AddingCommand, this, &ProgrammingWindow::onAddedCommand);
    connect(&CommandArray::instance(), &CommandArray::DeletingCommands, this, &ProgrammingWindow::onDeletingCommand);
}

void ProgrammingWindow::SetupUi(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array) {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(0, 0, 0, 0);
    gridlayout_main_->setSpacing(0);

    scrl_groups_ = new QScrollArea(this);
    cntnt_wdgt_groups_ = new ScrollAreaWidget(main_command, selected_fixture, dmx_fixture_array, ProgrammingType::Group);
    scrl_groups_->setWidget(cntnt_wdgt_groups_);

    scrl_cue_ = new QScrollArea(this);
    cntnt_wdgt_cue_ = new ScrollAreaWidget(main_command, nullptr, nullptr, ProgrammingType::Cue);
    scrl_cue_->setWidget(cntnt_wdgt_cue_);

    scrl_positions_ = new QScrollArea(this);
    cntnt_wdgt_positions_ = new ScrollAreaWidget(main_command, nullptr, nullptr, ProgrammingType::Position);
    scrl_positions_->setWidget(cntnt_wdgt_positions_);

    scrl_color_ = new QScrollArea(this);
    cntnt_wdgt_color_ = new ScrollAreaWidget(main_command, nullptr, nullptr, ProgrammingType::Color);
    scrl_color_->setWidget(cntnt_wdgt_color_);

    scrl_beam_ = new QScrollArea(this);
    cntnt_wdgt_beam_ = new ScrollAreaWidget(main_command, nullptr, nullptr, ProgrammingType::Beam);
    scrl_beam_->setWidget(cntnt_wdgt_beam_);

    scrl_focus_ = new QScrollArea(this);
    cntnt_wdgt_focus_ = new ScrollAreaWidget(main_command, nullptr, nullptr, ProgrammingType::Focus);
    scrl_focus_->setWidget(cntnt_wdgt_focus_);

    gridlayout_main_->addWidget(scrl_groups_, 0, 0, 1, 2);
    gridlayout_main_->addWidget(scrl_cue_, 1, 0, 1, 2);
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
