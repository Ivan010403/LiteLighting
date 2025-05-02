#include "scrollbarvalue.h"

ScrollBarValue::ScrollBarValue(QWidget* parent) : QScrollBar(Qt::Vertical, parent) {
    SetupUi();
}

void ScrollBarValue::SetupUi() {
    setFixedSize(65, 160);
    setMinimum(0);
    setMaximum(255);
    setValue(maximum());
}
