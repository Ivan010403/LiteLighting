#include "settingspanel.h"

SettingsPanel::SettingsPanel(QWidget* parent) : QWidget(parent) {
    SetupUi();
}

void SettingsPanel::SetupUi() {
    setAttribute(Qt::WA_StyledBackground, true); // чтобы можно было красить фон

    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(15, 15, 15, 15);
    btn_1 = new QPushButton(this);
    btn_2 = new QPushButton(this);
    btn_3 = new QPushButton(this);
    btn_4 = new QPushButton(this);
    btn_5 = new QPushButton(this);
    btn_6 = new QPushButton(this);
    btn_7 = new QPushButton(this);
    btn_8 = new QPushButton(this);
    btn_9 = new QPushButton(this);
    btn_1->setFixedSize(50, 50);
    btn_2->setFixedSize(50, 50);
    btn_3->setFixedSize(50, 50);
    btn_4->setFixedSize(50, 50);
    btn_5->setFixedSize(50, 50);
    btn_6->setFixedSize(50, 50);
    btn_7->setFixedSize(50, 50);
    btn_8->setFixedSize(50, 50);
    btn_9->setFixedSize(50, 50);
    vlayout_main_->addWidget(btn_1);
    vlayout_main_->addWidget(btn_2);
    vlayout_main_->addWidget(btn_3);
    vlayout_main_->addWidget(btn_4);
    vlayout_main_->addWidget(btn_5);
    vlayout_main_->addWidget(btn_6);
    vlayout_main_->addWidget(btn_7);
    vlayout_main_->addWidget(btn_8);
    vlayout_main_->addWidget(btn_9);
    vlayout_main_->setSpacing(20);
}
