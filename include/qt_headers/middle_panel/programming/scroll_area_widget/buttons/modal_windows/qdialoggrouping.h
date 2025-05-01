#ifndef QDIALOGGROUPING_H
#define QDIALOGGROUPING_H

#include <QDialog>

#include "light_headers/FixtureArray.h"

class QDialogGrouping : public QDialog {
Q_OBJECT

public:
    explicit QDialogGrouping(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) :
        dmx_fixture_array_(dmx_fixture_array),
        QDialog(parent)
    {
        SetupUi();
        SetupConnections();
    }

signals:
    void GroupCreating(const QModelIndexList& selected_indexes);

protected:
    void closeEvent(QCloseEvent* event) override {
        qDebug() <<"close event";
        hide();
        event->ignore();
    }

private slots:
    void onBtnClicked() {
        emit GroupCreating(selection_model_->selectedIndexes());
    }

private:
    void SetupUi() {
        setFixedSize(500, 300);

        vlayout_main_ = new QVBoxLayout(this);

        table_fixtures_ = new QTableView(this);
        table_fixtures_->setModel(dmx_fixture_array_);
        table_fixtures_->setSelectionMode(QAbstractItemView::ExtendedSelection);

        selection_model_ = table_fixtures_->selectionModel();


        btn_create_group_ = new QPushButton("Create group", this);

        vlayout_main_->addWidget(table_fixtures_, 3);
        vlayout_main_->addWidget(btn_create_group_, 1);

    }

    void SetupConnections() {
        connect(btn_create_group_, &QPushButton::clicked, this, &QDialogGrouping::onBtnClicked);
        connect(btn_create_group_, &QPushButton::clicked, this, &QDialogGrouping::accept); // что вызовется быстрее?
    }

    FixtureArrayModel* dmx_fixture_array_;

    QVBoxLayout* vlayout_main_;
    QTableView* table_fixtures_;
    QPushButton* btn_create_group_;

    QItemSelectionModel* selection_model_;
};

#endif // QDIALOGGROUPING_H
