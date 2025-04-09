#ifndef MIDDLEPANEL_H
#define MIDDLEPANEL_H
#include <QWidget>
#include <QStackedWidget>

#include "./programming/programmingwindow.h"
#include "./executors&buttons/execbuttonswindow.h"
#include "./busking/buskingwindow.h"
#include "./patch_sheet/patchsheetwindow.h"
#include "./settings/settingswindow.h"

class MiddlePanel : public QStackedWidget {
Q_OBJECT

public:
    explicit MiddlePanel(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) : QStackedWidget(parent) {
        SetupUi(dmx_fixture_array);
    }

    ~MiddlePanel() = default;

public slots:
    void showProgramming() {
        setCurrentIndex(0);
    }

    void showExecButtons() {
        setCurrentIndex(1);
    }

    void showBusking() {
        setCurrentIndex(2);
    }

    void showPatchSheet() {
        setCurrentIndex(3);
    }

    void showSettings() {
        setCurrentIndex(4);
    }

private:
    void SetupUi(FixtureArrayModel* dmx_fixture_array) {
        progr_window_ = new ProgrammingWindow(this);
        exc_btns_window_ = new ExecButtonsWindow(this);
        bskng_window_ = new BuskingWindow(this);
        ptch_sht_window_ = new PatchSheetWindow(dmx_fixture_array, this);
        stngs_window_ = new SettingsWindow(this);

        addWidget(progr_window_);
        addWidget(exc_btns_window_);
        addWidget(bskng_window_);
        addWidget(ptch_sht_window_);
        addWidget(stngs_window_);
    }

    ProgrammingWindow* progr_window_;
    ExecButtonsWindow* exc_btns_window_;
    BuskingWindow* bskng_window_;
    PatchSheetWindow* ptch_sht_window_;
    SettingsWindow* stngs_window_;


};

#endif // MIDDLEPANEL_H
