#ifndef PATCHSHEETWINDOW_H
#define PATCHSHEETWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "./patching_modal_window/qdialogpatching.h"

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
        hlayout_main_ = new QHBoxLayout(this);
        hlayout_main_->setContentsMargins(0, 0, 0, 0);

        gridlayout_groups_ = new QGridLayout();
        gridlayout_groups_->setContentsMargins(0, 0, 0, 0);
        gridlayout_groups_->setVerticalSpacing(10);

        table_groups_ = new QTableView(this);
        table_groups_->setModel(dmx_fixture_array_);
        table_groups_->setEditTriggers(QAbstractItemView::NoEditTriggers);

        btn_add_group_ = new QPushButton("Add group", this);
        btn_delete_group_ = new QPushButton("Delete group", this);
        btn_edit_group_ = new QPushButton("Edit group", this);

        gridlayout_groups_->addWidget(table_groups_, 0, 0, 1, 3);
        gridlayout_groups_->addWidget(btn_add_group_, 1, 0);
        gridlayout_groups_->addWidget(btn_delete_group_, 1, 1);
        gridlayout_groups_->addWidget(btn_edit_group_, 1, 2);


        gridlayout_fixtures_ = new QGridLayout();
        gridlayout_fixtures_->setContentsMargins(0, 0, 0, 0);
        gridlayout_fixtures_->setVerticalSpacing(10);

        table_fixtures_ = new QTableView(this);
        table_fixtures_->setModel(dmx_fixture_array_);
        table_fixtures_->setEditTriggers(QAbstractItemView::NoEditTriggers);


        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_delete_fixture_ = new QPushButton("Delete fixture", this);
        btn_edit_fixture_ = new QPushButton("Edit fixture", this);

        gridlayout_fixtures_->addWidget(table_fixtures_, 0, 0, 1, 3);
        gridlayout_fixtures_->addWidget(btn_add_fixture_, 1, 0);
        gridlayout_fixtures_->addWidget(btn_delete_fixture_, 1, 1);
        gridlayout_fixtures_->addWidget(btn_edit_fixture_, 1, 2);


        hlayout_main_->addLayout(gridlayout_groups_);
        hlayout_main_->addLayout(gridlayout_fixtures_);
        hlayout_main_->setSpacing(30);
    }

    void SetupConnections() {
        connect(btn_add_fixture_, &QPushButton::clicked, this, &PatchSheetWindow::OnBtnAddFxtrClicked);
    }

    QHBoxLayout* hlayout_main_;

    QGridLayout* gridlayout_groups_;
    QTableView* table_groups_;
    QPushButton* btn_add_group_;
    QPushButton* btn_delete_group_;
    QPushButton* btn_edit_group_;

    QGridLayout* gridlayout_fixtures_;
    QTableView* table_fixtures_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_delete_fixture_;
    QPushButton* btn_edit_fixture_;

    QDialogPatching* qdial_patching_;

    FixtureArrayModel* dmx_fixture_array_;
};

#endif // PATCHSHEETWINDOW_H
