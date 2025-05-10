#include "qdialogeditor.h"

QDialogEditor::QDialogEditor(QWidget* parent) : QDialog(parent) {
    SetupUi();
    SetupConnections();
}

void QDialogEditor::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogEditor::SetupUi() {
    hlayout_main_ = new QHBoxLayout(this);
    hlayout_main_->setContentsMargins(0,0,0,0);
    hlayout_main_->setSpacing(10);

    btn_delete_ = new QPushButton("Delete", this);
    btn_cancel_ = new QPushButton("Cancel", this);

    btn_delete_->setFixedSize(70, 30);
    btn_cancel_->setFixedSize(70, 30);

    hlayout_main_->addWidget(btn_delete_);
    hlayout_main_->addWidget(btn_cancel_);
}

void QDialogEditor::SetupConnections() {
    connect(btn_cancel_, &QPushButton::clicked, this, &QDialogEditor::reject);
    connect(btn_delete_, &QPushButton::clicked, this, &QDialogEditor::onDeleteClicked);
    connect(btn_delete_, &QPushButton::clicked, this, &QDialogEditor::accept);
}
