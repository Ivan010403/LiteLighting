#ifndef PATCHSHEETWINDOW_H
#define PATCHSHEETWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "./patching_modal_window/qdialogpatching.h"
#include "light_headers/fixture_array_delegates/universeaddressdelegate.h"

class PatchSheetWindow : public QWidget {
Q_OBJECT

public:
    explicit PatchSheetWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);

    ~PatchSheetWindow() = default;

private slots:
    void OnBtnAddFxtrClicked();

private:
    void SetupUi();

    void SetupConnections();

    QVBoxLayout* vlayout_main_;
    QTableView* table_fixtures_;

    QHBoxLayout* hlayout_btns_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_delete_fixture_;
    QPushButton* btn_edit_fixture_;

    QDialogPatching* qdial_patching_;

    FixtureArrayModel* dmx_fixture_array_;
};

#endif // PATCHSHEETWINDOW_H
