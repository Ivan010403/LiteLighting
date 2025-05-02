#ifndef PROGRAMMINGBUTTON_H
#define PROGRAMMINGBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>

#include "./modal_windows/qdialogcommand.h"
#include "light_headers/programming_command/abstractcommand.h"

class ProgrammingButton : public QPushButton {
Q_OBJECT

public:
    explicit ProgrammingButton(AbstractCommand** main_command, ProgrammingType type_channels, int number, QWidget* parent = nullptr);

    ~ProgrammingButton();
protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;

private slots:
    void onSaveClicked(const QString& name);

private:
    void SetupUi();

    void SetupConnections();

    void drawBackground(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);


    AbstractCommand** main_command_;
    AbstractCommand* current_command_ = nullptr;

    ProgrammingType type_channels_; // нигде не использую пока что!
    const int number_;

    QDialogCommand* qdial_save_command_;
};

#endif // PROGRAMMINGBUTTON_H
