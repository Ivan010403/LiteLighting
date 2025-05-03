#ifndef QDIALOGCOMMAND_H
#define QDIALOGCOMMAND_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCloseEvent>

class QDialogCommand : public QDialog {
    Q_OBJECT
public:
    explicit QDialogCommand(QWidget* parent = nullptr);

signals:
    void SaveClicked(const QString& name);

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onSaveClicked();

private:
    void SetupUi();

    void SetupConnections();

    QGridLayout* gridlayout_main_;

    QLineEdit* line_name_;
    QPushButton* btn_save_;
    QPushButton* btn_close_;
};

#endif // QDIALOGCOMMAND_H
