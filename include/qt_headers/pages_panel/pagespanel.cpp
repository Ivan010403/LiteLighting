#include "pagespanel.h"

PagesPanel::PagesPanel(QWidget* parent) : QWidget(parent) {
    SetupUi();
    SetupConnections();
}

void PagesPanel::SetupUi() {
    setAttribute(Qt::WA_StyledBackground, true); // чтобы можно было красить фон

    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(10, 30, 10, 40);
    btn_programming_ = new QPushButton("Programming", this);
    btn_exec_btns_ = new QPushButton("Executors & Buttons", this);
    btn_busking_ = new QPushButton("Busking", this);
    btn_patching_ = new QPushButton("Patch sheet", this);
    btn_settings_ = new QPushButton("Settings", this);
    btn_programming_->setFixedSize(200, 100);
    btn_exec_btns_->setFixedSize(200, 100);
    btn_busking_->setFixedSize(200, 100);
    btn_patching_->setFixedSize(200, 100);
    btn_settings_->setFixedSize(200, 100);
    vlayout_main_->addWidget(btn_programming_);
    vlayout_main_->addWidget(btn_exec_btns_);
    vlayout_main_->addWidget(btn_busking_);
    vlayout_main_->addWidget(btn_patching_);
    vlayout_main_->addWidget(btn_settings_);
    vlayout_main_->setSpacing(40);
}

void PagesPanel::SetupConnections() {
    connect(btn_programming_, &QPushButton::clicked, this, &PagesPanel::showProgramming);
    connect(btn_exec_btns_, &QPushButton::clicked, this, &PagesPanel::showExecButtons);
    connect(btn_busking_, &QPushButton::clicked, this, &PagesPanel::showBusking);
    connect(btn_patching_, &QPushButton::clicked, this, &PagesPanel::showPatchSheet);
    connect(btn_settings_, &QPushButton::clicked, this, &PagesPanel::showSettings);
}
