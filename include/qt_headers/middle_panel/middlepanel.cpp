#include "middlepanel.h"

MiddlePanel::MiddlePanel(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, QWidget* parent) : QStackedWidget(parent) {
    SetupUi(main_command, selected_fixture, dmx_fixture_array);
}

void MiddlePanel::showProgramming() {
    setCurrentIndex(0);
}

void MiddlePanel::showBusking() {
    setCurrentIndex(1);
}

void MiddlePanel::showPatchSheet() {
    setCurrentIndex(2);
}

void MiddlePanel::showSettings() {
    setCurrentIndex(3);
}

void MiddlePanel::SetupUi(AbstractCommand** main_command, Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array) {
    progr_window_ = new ProgrammingWindow(main_command, selected_fixture, dmx_fixture_array, this);
    bskng_window_ = new BuskingWindow(dmx_fixture_array, selected_fixture, this);
    ptch_sht_window_ = new PatchSheetWindow(dmx_fixture_array, this);
    stngs_window_ = new SettingsWindow(dmx_fixture_array, this);

    addWidget(progr_window_);
    addWidget(bskng_window_);
    addWidget(ptch_sht_window_);
    addWidget(stngs_window_);
}
