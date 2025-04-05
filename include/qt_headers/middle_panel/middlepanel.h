#ifndef MIDDLEPANEL_H
#define MIDDLEPANEL_H
#include <QWidget>

class MiddlePanel : public QWidget {
Q_OBJECT

public:
    explicit MiddlePanel(QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~MiddlePanel() = default;

private:
    void SetupUi() {

    }
};

#endif // MIDDLEPANEL_H
