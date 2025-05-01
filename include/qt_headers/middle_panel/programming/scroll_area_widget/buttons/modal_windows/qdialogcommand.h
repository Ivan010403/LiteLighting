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
    explicit QDialogCommand(QWidget* parent = nullptr) : QDialog(parent) {
        SetupUi();
        SetupConnections();
    }

signals:
    void SaveClicked(const QString& name);

protected:
    void closeEvent(QCloseEvent* event) override {
        hide();
        event->ignore();
    }

private slots:
    void onSaveClicked() {
        emit SaveClicked(line_name_->text());
    }

private:
    void SetupUi() {
        setFixedSize(300, 150);

        hlayout_main_ = new QGridLayout(this);

        line_name_ = new QLineEdit(this);
        btn_save_ = new QPushButton("Save command", this);
        btn_close_ = new QPushButton("Close", this);

        hlayout_main_->addWidget(line_name_, 0, 0, 1, 2);
        hlayout_main_->addWidget(btn_save_, 1, 0);
        hlayout_main_->addWidget(btn_close_, 1, 1);
    }

    void SetupConnections() {
        connect(btn_save_, &QPushButton::clicked, this, &QDialogCommand::onSaveClicked);
        connect(btn_save_, &QPushButton::clicked, this, &QDialogCommand::hide); // успеет ли отправить до тех пор пока не сохранится?
        connect(btn_close_, &QPushButton::clicked, this, &QDialogCommand::hide);
    }

    QGridLayout* hlayout_main_;

    QLineEdit* line_name_;
    QPushButton* btn_save_;
    QPushButton* btn_close_;
};

#endif // QDIALOGCOMMAND_H
