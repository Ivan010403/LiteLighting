#ifndef QDIALOGPATCHING_H
#define QDIALOGPATCHING_H
#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "light_headers/Patcher.h"


class QDialogPatching : public QDialog {
    Q_OBJECT

public:
    explicit QDialogPatching(Patcher* dmx_patcher, QWidget* parent = nullptr) : dmx_patcher_(dmx_patcher), QDialog(parent) {}
    ~QDialogPatching() {}

    void Setup() {
        this->resize(1280,720);
        this->setMinimumSize(1280,720);

        vlayout_main_ = new QVBoxLayout();
        vlayout_main_->setSpacing(40);

        table_fixtures_ = new QTableWidget(2, 3, this);
        table_fixtures_->setHorizontalHeaderLabels(QStringList() << "Col 1" << "Col 2" << "Col 3");
        table_fixtures_->setVerticalHeaderLabels(QStringList() << "Row 1" << "Row 2" << "Row 3");

        hlayout_btns_ = new QHBoxLayout();
        hlayout_btns_->setSpacing(40);
        // hlayout_btns_->setContentsMargins(15,-1.15.-1);

        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_add_fixture_->setEnabled(true);

        btn_delete_fixture_ = new QPushButton("Delete fixture", this);
        btn_delete_fixture_->setEnabled(true);

        hlayout_btns_->addWidget(btn_add_fixture_);
        hlayout_btns_->addWidget(btn_delete_fixture_);

        hlayout_btns_->setStretch(0, 1);
        hlayout_btns_->setStretch(1, 1);

        vlayout_main_->addWidget(table_fixtures_);
        vlayout_main_->addLayout(hlayout_btns_);
        vlayout_main_->setStretch(0,3);
        vlayout_main_->setStretch(1,1);

        this->setLayout(vlayout_main_);

        SetupConnections();
    }

private slots:
    void onBtnAddClicked() {
        ChannelType* test = new ChannelType[2] {ChannelType::Dimmer, ChannelType::Pan};
        dmx_patcher_->PatchNewFixture(0, 0, 2, "test", test);
        qDebug() << "Кнопка AddFixture нажата!";
    }

    void onBtnDeleteClicked() {
        qDebug() << "Кнопка DeleteFixture нажата!";
    }

private:
    void SetupConnections(){
        connect(btn_add_fixture_, &QPushButton::clicked, this, &QDialogPatching::onBtnAddClicked);
        connect(btn_delete_fixture_, &QPushButton::clicked, this, &QDialogPatching::onBtnDeleteClicked);
    }


    QVBoxLayout* vlayout_main_;
    QHBoxLayout* hlayout_btns_;
    QTableWidget* table_fixtures_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_delete_fixture_;

    Patcher* dmx_patcher_;
};

#endif // QDIALOGPATCHING_H
