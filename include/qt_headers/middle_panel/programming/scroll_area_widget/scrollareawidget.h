#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H

#include "./buttons/typebutton.h"
#include "./buttons/programmingbutton.h"
#include "./buttons/groupbutton.h"

class ScrollAreaWidget : public QWidget {
    Q_OBJECT
public:
    explicit ScrollAreaWidget(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, ProgrammingType scrl_area_type, QWidget* parent = nullptr);

    ~ScrollAreaWidget() = default;

    ProgrammingButton* GetProgrammButton(int number);
private:
    void SetupUi();

    void AddButtons(int count);

    AbstractCommand** main_command_;
    Fixture** selected_fixture_;
    FixtureArrayModel* dmx_fixture_array_;
    ProgrammingType type_channels_;

    int current_count_ = 1;
    int columns_per_row_;

    const int button_size_ = 60;
    int batch_size_;

    QGridLayout* gridlayout_main_;
};

#endif // SCROLLAREAWIDGET_H
