#include "qdialogsocket.h"

QDialogSocket::QDialogSocket(QWidget* parent) : QDialog(parent) {
    SetupUi();
    SetupConnections();
}

void QDialogSocket::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogSocket::onSaveClicked() {
    emit SaveClicked(spn_box_number_->value());
}

void QDialogSocket::SetupUi() {
    setFixedSize(300, 150);

    gridlayout_main_ = new QGridLayout(this);

    spn_box_number_ = new QSpinBox(this);
    spn_box_number_->setMinimum(1);
    spn_box_number_->setMaximum(15);
    btn_save_ = new QPushButton("Save socket", this);
    btn_close_ = new QPushButton("Close", this);

    btn_save_->setFixedHeight(30);
    btn_close_->setFixedHeight(30);

    gridlayout_main_->addWidget(spn_box_number_, 0, 0, 1, 2);
    gridlayout_main_->addWidget(btn_save_, 1, 0);
    gridlayout_main_->addWidget(btn_close_, 1, 1);
}

void QDialogSocket::SetupConnections() {
    connect(btn_save_, &QPushButton::clicked, this, &QDialogSocket::onSaveClicked);
    connect(btn_save_, &QPushButton::clicked, this, &QDialogSocket::accept); // успеет ли отправить до тех пор пока не сохранится?
    connect(btn_close_, &QPushButton::clicked, this, &QDialogSocket::reject);
}
