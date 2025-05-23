#ifndef SCROLLBARVALUE_H
#define SCROLLBARVALUE_H

#include <QScrollBar>

class ScrollBarValue : public QScrollBar {
public:
    explicit ScrollBarValue(QWidget* parent = nullptr);

    ~ScrollBarValue() = default;

private:
    void SetupUi();
};

#endif // SCROLLBARVALUE_H
