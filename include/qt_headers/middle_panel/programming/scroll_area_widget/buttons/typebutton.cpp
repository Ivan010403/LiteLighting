#include "typebutton.h"

TypeButton::TypeButton(ProgrammingType type, QWidget* parent) : QPushButton(map_programming_to_qstring[type], parent) {
    SetupUi();
}

void TypeButton::SetupUi() {
    setFixedSize(60, 60);
}
