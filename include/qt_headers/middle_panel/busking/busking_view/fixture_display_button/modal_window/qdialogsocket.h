#ifndef QDIALOGSOCKET_H
#define QDIALOGSOCKET_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCloseEvent>

class QDialogSocket : public QDialog {
    Q_OBJECT
public:
    explicit QDialogSocket(QWidget* parent = nullptr);

signals:
    void SaveClicked(int value);

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onSaveClicked();

private:
    void SetupUi();

    void SetupConnections();

    QGridLayout* gridlayout_main_;

    QSpinBox* spn_box_number_;
    QPushButton* btn_save_;
    QPushButton* btn_close_;
};

#endif // QDIALOGSOCKET_H
