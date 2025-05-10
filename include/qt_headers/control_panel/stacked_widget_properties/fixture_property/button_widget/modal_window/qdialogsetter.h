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
    explicit QDialogSetter(ChannelType type, QWidget* parent = nullptr);

    ~QDialogSetter() = default;

    int exec() override;

signals:
    void BtnClicking(int, int);

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void OnBtnClicked();

private:
    void SetupUi();

    void SetupConnections();

    QVBoxLayout* vlayout_main_;
    QLineEdit* line_edit_value_;
    QPushButton* btn_send_value_;

    QComboBox* cmb_box_type_ = nullptr;

    const ChannelType type_channel_;
    ChannelType flex_type_;
};

#endif // QDIALOGSETTER_H
