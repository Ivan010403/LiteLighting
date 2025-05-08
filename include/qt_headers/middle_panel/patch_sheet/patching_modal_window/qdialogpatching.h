#ifndef QDIALOGHELPER_H
#define QDIALOGHELPER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

#include "light_headers/FixtureArray.h"

// TODO: сделать нормальну валидацию, чтобы исключить ошибки любого рода

class QDialogPatching : public QDialog {
    Q_OBJECT
public:
    explicit QDialogPatching(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);

    ~QDialogPatching();

    int exec() override;

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void OnBtnClicked();
    void OnChannelAmountEntered();
    void OnIndexChanged(int index);

private:
    void SetupUi();

    void SetupConnections();

    QGridLayout* gridlayout_main_;

    QLabel* label_name_;
    QLabel* label_fixture_id_;
    QLabel* label_universe_id_;
    QLabel* label_dmx_address_;
    QLabel* label_channel_amount_;
    QLabel* label_patching_;

    QLineEdit* linedit_name_;
    QLineEdit* linedit_fixture_id_;
    QLineEdit* linedit_universe_id_;
    QLineEdit* linedit_dmx_address_;
    QLineEdit* linedit_channel_amount_;
    QComboBox* qcmbox_patching_;

    QPushButton* btn_enter_fixture_;

    FixtureArrayModel* dmx_fixture_array_;
    ChannelType* channels = nullptr; // проверить на утечку
    uint16_t channel_amount_ = 0;
    uint16_t current_order_channel_ = 0;

    QIntValidator* validator;
};

#endif // QDIALOGHELPER_H
