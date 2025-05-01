#ifndef SCROLLBARVALUE_H
#define SCROLLBARVALUE_H

#include <QScrollBar>

class ScrollBarValue : public QScrollBar {
Q_OBJECT

public:
    explicit ScrollBarValue(QWidget* parent = nullptr) : QScrollBar(Qt::Vertical, parent) {
        SetupUi();
    }

    ~ScrollBarValue() = default;

private:
    void SetupUi() {
        setFixedSize(65, 160);
        setMinimum(0);
        setMaximum(255);
        setValue(maximum());
    }
};

#endif // SCROLLBARVALUE_H
