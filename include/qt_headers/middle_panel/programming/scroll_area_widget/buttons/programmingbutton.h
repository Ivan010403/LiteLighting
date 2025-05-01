#ifndef PROGRAMMINGBUTTON_H
#define PROGRAMMINGBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

#include "./command_modal_window/qdialogcommand.h"
#include "light_headers/programming_command/abstractcommand.h"

class ProgrammingButton : public QPushButton {
Q_OBJECT

public:
    explicit ProgrammingButton(AbstractCommand** main_command, ProgrammingType type_channels, QWidget* parent = nullptr) :
        main_command_(main_command),
        type_channels_(type_channels),
        QPushButton(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~ProgrammingButton() {
        delete current_command_;
    } // опасно

protected:
    void mousePressEvent(QMouseEvent* event) override {
        if ((event->button() == Qt::RightButton) && (!current_command_)) { // а если мэйн команда пустая???
            qdial_save_command_->show();
        } else {
            QPushButton::mousePressEvent(event);
        }
    }

    void mouseDoubleClickEvent(QMouseEvent* event) override {
        if ((event->button() == Qt::LeftButton) && (current_command_)) {
            qDebug() << "Double click detected!";
            current_command_->execute();
        }
        // Вызываем базовую реализацию (если нужно)
        // QPushButton::mouseDoubleClickEvent(event);
    }

private slots:
    void onSaveClicked(const QString& name) {
        current_command_ = *main_command_;
        *main_command_ = new AbstractCommand();
        qDebug() << "сохранение команды";
        setText(name);
    }

private:
    void SetupUi() {
        setFixedSize(60, 60);

        qdial_save_command_ = new QDialogCommand(this);
    }

    void SetupConnections() {
        connect(qdial_save_command_, &QDialogCommand::SaveClicked, this, &ProgrammingButton::onSaveClicked);
    }

    AbstractCommand** main_command_;
    AbstractCommand* current_command_ = nullptr;

    ProgrammingType type_channels_;

    QDialogCommand* qdial_save_command_;
};

#endif // PROGRAMMINGBUTTON_H
