#include "qdialogcommand.h"

QDialogCommand::QDialogCommand(QWidget* parent) : QDialog(parent) {
    SetupUi();
    SetupConnections();
}

void QDialogCommand::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogCommand::onSaveClicked() {
    emit SaveClicked(line_name_->text());
}

void QDialogCommand::SetupUi() {
    setFixedSize(300, 150);

    gridlayout_main_ = new QGridLayout(this);

    line_name_ = new QLineEdit(this);
    btn_save_ = new QPushButton("Save command", this);
    btn_close_ = new QPushButton("Close", this);

    gridlayout_main_->addWidget(line_name_, 0, 0, 1, 2);
    gridlayout_main_->addWidget(btn_save_, 1, 0);
    gridlayout_main_->addWidget(btn_close_, 1, 1);
}

void QDialogCommand::SetupConnections() {
    connect(btn_save_, &QPushButton::clicked, this, &QDialogCommand::onSaveClicked);
    connect(btn_save_, &QPushButton::clicked, this, &QDialogCommand::accept); // успеет ли отправить до тех пор пока не сохранится?
    connect(btn_close_, &QPushButton::clicked, this, &QDialogCommand::reject);
}
