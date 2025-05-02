#include "qdialoggrouping.h"

QDialogGrouping::QDialogGrouping(FixtureArrayModel* dmx_fixture_array, QWidget* parent) :
    QDialog(parent)
{
    SetupUi(dmx_fixture_array);
    SetupConnections();
}

void QDialogGrouping::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogGrouping::onBtnClicked() {
    emit GroupCreating(selection_model_->selectedIndexes());
}

void QDialogGrouping::SetupUi(FixtureArrayModel* dmx_fixture_array) {
    setFixedSize(500, 300);

    vlayout_main_ = new QVBoxLayout(this);

    table_fixtures_ = new QTableView(this);
    table_fixtures_->setModel(dmx_fixture_array);
    table_fixtures_->setSelectionMode(QAbstractItemView::ExtendedSelection);

    selection_model_ = table_fixtures_->selectionModel();


    btn_create_group_ = new QPushButton("Create group", this);

    vlayout_main_->addWidget(table_fixtures_, 3);
    vlayout_main_->addWidget(btn_create_group_, 1);

}

void QDialogGrouping::SetupConnections() {
    connect(btn_create_group_, &QPushButton::clicked, this, &QDialogGrouping::onBtnClicked);
    connect(btn_create_group_, &QPushButton::clicked, this, &QDialogGrouping::accept); // что вызовется быстрее?
}
