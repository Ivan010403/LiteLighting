#ifndef PROGRAMMINGBUTTON_H
#define PROGRAMMINGBUTTON_H

#include <QWidget>
#include <QPushButton>

class ProgrammingButton : public QPushButton {
Q_OBJECT

public:
    explicit ProgrammingButton(QWidget* parent = nullptr) : QPushButton(parent) {
        SetupUi();
    }

    ~ProgrammingButton() = default;

private:
    void SetupUi() {
        setFixedSize(60, 60);


    }
};

#endif // PROGRAMMINGBUTTON_H
