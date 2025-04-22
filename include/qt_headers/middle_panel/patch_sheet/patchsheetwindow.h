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
    explicit PatchSheetWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) : dmx_fixture_array_(dmx_fixture_array), QWidget(parent) {
        qdial_patching_ = new QDialogPatching(dmx_fixture_array, this);

        SetupUi();
        SetupConnections();
    }

    ~PatchSheetWindow() = default;

private slots:
    void OnBtnAddFxtrClicked() {
        qdial_patching_->show();
    }

private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(0, 0, 0, 0);
        // vlayout_main_->setVerticalSpacing(10);

        table_fixtures_ = new QTableView(this);
        table_fixtures_->setModel(dmx_fixture_array_);
        // table_fixtures_->setItemDelegateForColumn(0, new FixtureArrayModelDelegate());
        // table_fixtures_->setItemDelegateForColumn(1, new FixtureArrayModelDelegate());
        table_fixtures_->setItemDelegateForColumn(2, new UniverseAddressDelegate());



        hlayout_btns_ = new QHBoxLayout();
        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_delete_fixture_ = new QPushButton("Delete fixture", this);
        btn_edit_fixture_ = new QPushButton("Edit fixture", this);

        hlayout_btns_->addWidget(btn_add_fixture_);
        hlayout_btns_->addWidget(btn_delete_fixture_);
        hlayout_btns_->addWidget(btn_edit_fixture_);

        vlayout_main_->addWidget(table_fixtures_, 4);
        vlayout_main_->addLayout(hlayout_btns_, 1);
    }

    void SetupConnections() {
        connect(btn_add_fixture_, &QPushButton::clicked, this, &PatchSheetWindow::OnBtnAddFxtrClicked);
    }

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
