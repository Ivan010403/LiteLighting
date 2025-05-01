#ifndef TYPEBUTTON_H
#define TYPEBUTTON_H

#include <QWidget>
#include <QPushButton>

#include "light_headers/CustomTypeEnum.h"

class TypeButton : public QPushButton {
Q_OBJECT

public:
    explicit TypeButton(ProgrammingType type, QWidget* parent = nullptr) : QPushButton(map_programming_to_qstring[type], parent) {
        SetupUi();
    }

    ~TypeButton() = default;

private:
    void SetupUi() {
        setFixedSize(60, 60);
    }
};

#endif // TYPEBUTTON_H
