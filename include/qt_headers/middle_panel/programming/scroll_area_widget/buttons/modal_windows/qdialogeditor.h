#ifndef QDIALOGEDITOR_H
#define QDIALOGEDITOR_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCloseEvent>

class QDialogEditor : public QDialog {
    Q_OBJECT
public:
    explicit QDialogEditor(QWidget* parent = nullptr);

signals:
    void onDeleteClicked();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    void SetupUi();

    void SetupConnections();

    QHBoxLayout* hlayout_main_;
    QPushButton* btn_delete_;
    QPushButton* btn_cancel_;
};

#endif // QDIALOGEDITOR_H
