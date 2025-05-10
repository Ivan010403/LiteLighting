#include "qdialogsetter.h"

QDialogSetter::QDialogSetter(ChannelType type, QWidget* parent) :
    type_channel_(type),
    QDialog(parent)
{
    SetupUi();
    SetupConnections();
}

int QDialogSetter::exec() {
    line_edit_value_->clear();
    if (cmb_box_type_) cmb_box_type_->setCurrentIndex(0);

    return QDialog::exec();
}

void QDialogSetter::closeEvent(QCloseEvent* event) {
    hide();
    event->ignore();
}

void QDialogSetter::OnBtnClicked() {
    if (cmb_box_type_) emit BtnClicking(line_edit_value_->text().toInt(), cmb_box_type_->currentIndex());
    else emit BtnClicking(line_edit_value_->text().toInt(), 0);
}

void QDialogSetter::SetupUi() {
    vlayout_main_ = new QVBoxLayout(this);
    vlayout_main_->setContentsMargins(0,0,0,0);
    vlayout_main_->setSpacing(10);

    line_edit_value_ = new QLineEdit(this);
    QIntValidator* intValidator = new QIntValidator(0, 255, line_edit_value_);
    line_edit_value_->setValidator(intValidator);
    btn_send_value_ = new QPushButton("Send data", this);

    if (type_channel_ == ChannelType::Flex) {
        cmb_box_type_ = new QComboBox(this);
        cmb_box_type_->addItem("Flex");

        for (int i = 0; i < static_cast<int>(ChannelType::Flex); ++i) {
            cmb_box_type_->addItem(ChannelTypeToQString(static_cast<ChannelType>(i)));
        }
        vlayout_main_->addWidget(cmb_box_type_);
    }

    vlayout_main_->addWidget(line_edit_value_);
    vlayout_main_->addWidget(btn_send_value_);
}

void QDialogSetter::SetupConnections() {
    connect(btn_send_value_, &QPushButton::clicked, this, &QDialogSetter::OnBtnClicked);
    connect(btn_send_value_, &QPushButton::clicked, this, &QDialogSetter::accept);

    connect(line_edit_value_, &QLineEdit::textChanged, [=](const QString &text) {
        if (text.startsWith('0') && text.length() > 1) {
            line_edit_value_->setText(text.mid(1));
        }
    });
    connect(line_edit_value_, &QLineEdit::editingFinished, [=]() {
        if (line_edit_value_->text().isEmpty()) {
            line_edit_value_->setText("0");
        }
    });
}
