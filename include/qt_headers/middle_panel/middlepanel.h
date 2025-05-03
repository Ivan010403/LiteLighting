#ifndef MIDDLEPANEL_H
#define MIDDLEPANEL_H

#include <QStackedWidget>

#include "./programming/programmingwindow.h"
#include "./executors&buttons/execbuttonswindow.h"
#include "./busking/buskingwindow.h"
#include "./patch_sheet/patchsheetwindow.h"
#include "./settings/settingswindow.h"

class MiddlePanel : public QStackedWidget {
Q_OBJECT

public:
    explicit MiddlePanel(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);

    ~MiddlePanel() = default;

public slots:
    void showProgramming();
    void showExecButtons();
    void showBusking();
    void showPatchSheet();
    void showSettings();

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array);

    ProgrammingWindow* progr_window_;
    ExecButtonsWindow* exc_btns_window_;
    BuskingWindow* bskng_window_;
    PatchSheetWindow* ptch_sht_window_;
    SettingsWindow* stngs_window_;
};

#endif // MIDDLEPANEL_H
