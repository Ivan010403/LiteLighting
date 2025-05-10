#include "patchsheetwindow.h"

PatchSheetWindow::PatchSheetWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent) :
    dmx_fixture_array_(dmx_fixture_array),
    QWidget(parent)
{
    qdial_patching_ = new QDialogPatching(dmx_fixture_array, this);

    SetupUi();
    SetupConnections();
}


void PatchSheetWindow::OnBtnAddFxtrClicked() {
    qdial_patching_->exec();
}

void PatchSheetWindow::OnBtnDeleteFxtrClicked() {
    if (selection_model_->selectedIndexes().size() != 0) {
        QSet<int> unique_rows;
        for (const QModelIndex& index : selection_model_->selectedIndexes()) {
            if (index.isValid()) {
                unique_rows.insert(index.row());
            }
        }

        for (const int var : unique_rows) {
            qDebug() << "PatchSheetWindow::OnBtnDeleteFxtrClicked() --> удаление фикстуры с index = " << var;
            dmx_fixture_array_->DeleteFixture(var);
        }
    }
}


void PatchSheetWindow::SetupUi() {
    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0, 0, 0, 0);
    vlayout_main_->setSpacing(0);

    table_fixtures_ = new QTableView(this);
    table_fixtures_->setModel(dmx_fixture_array_);
    table_fixtures_->setItemDelegateForColumn(2, new UniverseAddressDelegate(table_fixtures_));
    table_fixtures_->setSelectionMode(QAbstractItemView::ExtendedSelection);

    table_fixtures_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    selection_model_ = table_fixtures_->selectionModel();


    hlayout_btns_ = new QHBoxLayout();
    hlayout_btns_->setContentsMargins(10, 0, 10, 0);
    hlayout_btns_->setSpacing(10);

    btn_add_fixture_ = new QPushButton("Add fixture", this);
    btn_delete_fixture_ = new QPushButton("Delete fixture", this);
    btn_add_fixture_->setFixedHeight(30);
    btn_delete_fixture_->setFixedHeight(30);

    hlayout_btns_->addWidget(btn_add_fixture_);
    hlayout_btns_->addWidget(btn_delete_fixture_);

    vlayout_main_->addWidget(table_fixtures_, 4);
    vlayout_main_->addLayout(hlayout_btns_, 1);
}

void PatchSheetWindow::SetupConnections() {
    connect(btn_add_fixture_, &QPushButton::clicked, this, &PatchSheetWindow::OnBtnAddFxtrClicked);
    connect(btn_delete_fixture_, &QPushButton::clicked, this, &PatchSheetWindow::OnBtnDeleteFxtrClicked);
}
