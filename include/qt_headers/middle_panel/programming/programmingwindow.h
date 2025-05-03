#ifndef PROGRAMMINGWINDOW_H
#define PROGRAMMINGWINDOW_H

#include <QGridLayout>
#include <QScrollArea>

#include "./scroll_area_widget/scrollareawidget.h"

class ProgrammingWindow : public QWidget {
    Q_OBJECT
public:
    explicit ProgrammingWindow(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);

    ~ProgrammingWindow() = default;

private slots:
    void onAddedCommand(ProgrammingType type, int number, AbstractCommand* command);

private:
    void SetupConnections();
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array);

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
