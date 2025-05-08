#ifndef QDIALOGSETTER_H
#define QDIALOGSETTER_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QPushButton>

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

        return QDialog::exec();
    }

signals:
    void BtnClicking(int value);

protected:
    void closeEvent(QCloseEvent* event) override {
        hide();
        event->ignore();
    }

private slots:
    void OnBtnClicked() {
        // может быть не число!
        emit BtnClicking(line_edit_value_->text().toInt());
    }

private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(0,0,0,0);
        vlayout_main_->setSpacing(10);

        line_edit_value_ = new QLineEdit(this);
        btn_send_value_ = new QPushButton("Send data", this);

        vlayout_main_->addWidget(line_edit_value_);
        vlayout_main_->addWidget(btn_send_value_);
    }

    void SetupConnections() {
        connect(btn_send_value_, &QPushButton::clicked, this, &QDialogSetter::OnBtnClicked);
        connect(btn_send_value_, &QPushButton::clicked, this, &QDialogSetter::accept);
    }

    QVBoxLayout* vlayout_main_;
    QLineEdit* line_edit_value_;
    QPushButton* btn_send_value_;

    const ChannelType type_channel_;
};

#endif // QDIALOGSETTER_H
