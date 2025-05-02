#ifndef TYPEBUTTON_H
#define TYPEBUTTON_H

#include <QWidget>
#include <QPushButton>

#include "light_headers/CustomTypeEnum.h"

class TypeButton : public QPushButton {
Q_OBJECT

public:
    explicit TypeButton(ProgrammingType type, QWidget* parent = nullptr);

    ~TypeButton() = default;

private:
    void SetupUi();
};

#endif // TYPEBUTTON_H
