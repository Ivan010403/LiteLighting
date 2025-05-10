#ifndef PATCHSHEETWINDOW_H
#define PATCHSHEETWINDOW_H

#include <QWidget>
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
    void OnBtnDeleteFxtrClicked();

private:
    void SetupUi();

    void SetupConnections();

    QVBoxLayout* vlayout_main_;
    QTableView* table_fixtures_;

    QHBoxLayout* hlayout_btns_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_delete_fixture_;

    QDialogPatching* qdial_patching_;

    FixtureArrayModel* dmx_fixture_array_;

    QItemSelectionModel* selection_model_;
};

#endif // PATCHSHEETWINDOW_H
