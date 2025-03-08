#ifndef QDIALOGPATCHING_H
#define QDIALOGPATCHING_H
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QGridLayout>

#include <QPushButton>

#include "qdialoghelper.h"


class QDialogPatching : public QDialog {
    Q_OBJECT

public:
    explicit QDialogPatching(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) : dmx_fixture_array_(dmx_fixture_array), QDialog(parent) {
        SetupUi();
        SetupConnections();
    }

    ~QDialogPatching() {}

private slots:
    void onBtnAddClicked() {

        //  REFACTOR THIS!!!!
        // ChannelType* test = new ChannelType[2] {ChannelType::Dimmer, ChannelType::Pan};
        // dmx_patcher_->PatchNewFixture(10, 0, 0, 2, "test", test);
        //  REFACTOR THIS!!!!
        qdial_helper_->show();
    }

    void onBtnDeleteClicked() {
        qDebug() << "Кнопка DeleteFixture нажата!";
    }

private:
    void SetupUi() {
        this->resize(1280,720);
        this->setMinimumSize(1280,720);
        this->setWindowTitle("Fixture patching");


        gridlayout_main_ = new QGridLayout(this);


        table_groups_ = new QTableView(this);
        table_groups_->setModel(dmx_fixture_array_);

        table_fixtures_ = new QTableView(this);
        table_fixtures_->setModel(dmx_fixture_array_);


        gridlayout_main_->addWidget(table_groups_, 0, 0);
        gridlayout_main_->addWidget(table_fixtures_, 0, 1);


        gridlayout_groups_ = new QGridLayout();

        btn_add_group_ = new QPushButton("Add group", this);
        btn_delete_group_ = new QPushButton("Delete group", this);
        btn_change_group_ = new QPushButton("Change group", this);

        gridlayout_groups_->addWidget(btn_add_group_, 0, 0);
        gridlayout_groups_->addWidget(btn_delete_group_, 0, 1);
        gridlayout_groups_->addWidget(btn_change_group_, 0, 2);

        // затычка и костыль
        gridlayout_groups_->addWidget(new QPushButton("Test", this), 1, 0);
        gridlayout_groups_->addWidget(new QPushButton("Test", this), 1, 1);
        gridlayout_groups_->addWidget(new QPushButton("Test", this), 1, 2);
        //------------------

        gridlayout_fixtures_ = new QGridLayout();

        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_delete_fixture_ = new QPushButton("Delete fixture", this);
        btn_change_fixture_ = new QPushButton("Change fixture", this);

        gridlayout_fixtures_->addWidget(btn_add_fixture_, 0, 0);
        gridlayout_fixtures_->addWidget(btn_delete_fixture_, 0, 1);
        gridlayout_fixtures_->addWidget(btn_change_fixture_, 0, 2);

        // затычка и костыль
        gridlayout_fixtures_->addWidget(new QPushButton("Test", this), 1, 0);
        gridlayout_fixtures_->addWidget(new QPushButton("Test", this), 1, 1);
        gridlayout_fixtures_->addWidget(new QPushButton("Test", this), 1, 2);
        //------------------

        gridlayout_main_->addLayout(gridlayout_groups_, 1, 0);
        gridlayout_main_->addLayout(gridlayout_fixtures_, 1, 1);

        qdial_helper_ = new QDialogHelper(dmx_fixture_array_, this);
    }

    void SetupConnections(){
        connect(btn_add_fixture_, &QPushButton::clicked, this, &QDialogPatching::onBtnAddClicked);
        connect(btn_delete_fixture_, &QPushButton::clicked, this, &QDialogPatching::onBtnDeleteClicked);
    }


    QGridLayout* gridlayout_main_;

    QTableView* table_groups_;
    QTableView* table_fixtures_;

    QGridLayout* gridlayout_groups_;
    QPushButton* btn_add_group_;
    QPushButton* btn_delete_group_;
    QPushButton* btn_change_group_;

    QGridLayout* gridlayout_fixtures_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_delete_fixture_;
    QPushButton* btn_change_fixture_;

    QDialogHelper* qdial_helper_;

    FixtureArrayModel* dmx_fixture_array_;
};

#endif // QDIALOGPATCHING_H
