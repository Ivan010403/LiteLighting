#include "scrollareawidget.h"

ScrollAreaWidget::ScrollAreaWidget(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, ProgrammingType scrl_area_type, QWidget* parent) :
    main_command_(main_command),
    selected_fixture_(selected_fixture),
    dmx_fixture_array_(dmx_fixture_array),
    type_channels_(scrl_area_type),
    QWidget(parent)
{
    columns_per_row_ = (scrl_area_type == ProgrammingType::Group || scrl_area_type == ProgrammingType::Cue) ? 20 : 10;

    batch_size_ = (scrl_area_type == ProgrammingType::Group || scrl_area_type == ProgrammingType::Cue ||
                   scrl_area_type == ProgrammingType::Focus || scrl_area_type == ProgrammingType::Beam ) ? 40 : 50;

    SetupUi();
    AddButtons(batch_size_);
}

ProgrammingButton* ScrollAreaWidget::GetProgrammButton(int number) {
    if (number >= current_count_ - 1) AddButtons(batch_size_);
    return qobject_cast<ProgrammingButton*>(gridlayout_main_->itemAt(number)->widget());
}

void ScrollAreaWidget::onEndedButtons() {
    AddButtons(batch_size_);
}

void ScrollAreaWidget::SetupUi() {
    gridlayout_main_ = new QGridLayout(this);
    gridlayout_main_->setContentsMargins(16, 16, 10, 16);
    gridlayout_main_->setSpacing(15);
}

void ScrollAreaWidget::AddButtons(int count) {
    if (current_count_ == 1) {
        TypeButton* button = new TypeButton(type_channels_, this);
        button->setFixedSize(button_size_, button_size_);
        gridlayout_main_->addWidget(button, 0, 0);
    }

    for (int i = 1; i < count; ++i) {
        if (type_channels_ == ProgrammingType::Group) {
            GroupButton* button = new GroupButton(selected_fixture_, dmx_fixture_array_,  current_count_, ptr_current_amount_, this);
            button->setFixedSize(button_size_, button_size_);
            connect(button, &GroupButton::onEndedButtons, this, &ScrollAreaWidget::onEndedButtons);

            int row = current_count_ / columns_per_row_;
            int column = current_count_ % columns_per_row_;

            gridlayout_main_->addWidget(button, row, column);
        }
        else {
            ProgrammingButton* button = new ProgrammingButton(main_command_, type_channels_,  current_count_, ptr_current_amount_, this);
            button->setFixedSize(button_size_, button_size_);
            connect(button, &ProgrammingButton::onEndedButtons, this, &ScrollAreaWidget::onEndedButtons);

            int row = current_count_ / columns_per_row_;
            int column = current_count_ % columns_per_row_;

            gridlayout_main_->addWidget(button, row, column);
        }

        ++current_count_;
    }

    adjustSize();
}
