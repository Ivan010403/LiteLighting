#include "typebutton.h"

TypeButton::TypeButton(ProgrammingType type, QWidget* parent) : QPushButton(ProgrammingTypeToQString(type), parent) {
    SetupUi();
}

void TypeButton::SetupUi() {
    setFixedSize(60, 60);
}
