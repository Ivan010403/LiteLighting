#ifndef QDIALOGSETTER_H
#define QDIALOGSETTER_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QPushButton>
#include <QComboBox>
#include <QIntValidator>

#include "light_headers/CustomTypeEnum.h"

class QDialogSetter : public QDialog {
    Q_OBJECT
public:
    explicit QDialogSetter(ChannelType type, QWidget* parent = nullptr) :
        type_channel_(type),
        QDialog(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~QDialogSetter() = default;

    int exec() override {
        line_edit_value_->clear();
        if (cmb_box_type_) cmb_box_type_->setCurrentIndex(0);

        return QDialog::exec();
    }

signals:
    void BtnClicking(int, int);

protected:
    void closeEvent(QCloseEvent* event) override {
        hide();
        event->ignore();
    }

private slots:
    void OnBtnClicked() {
        // может быть не число!
        if (cmb_box_type_) emit BtnClicking(line_edit_value_->text().toInt(), cmb_box_type_->currentIndex());
        else emit BtnClicking(line_edit_value_->text().toInt(), 0);
    }

private:
    void SetupUi() {
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

    void SetupConnections() {
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

    QVBoxLayout* vlayout_main_;
    QLineEdit* line_edit_value_;
    QPushButton* btn_send_value_;

    QComboBox* cmb_box_type_ = nullptr;

    const ChannelType type_channel_;
    ChannelType flex_type_;
};

#endif // QDIALOGSETTER_H
