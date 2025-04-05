#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include <QWidget>

class ControlPanel : public QWidget
{
Q_OBJECT

public:
    explicit ControlPanel(QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~ControlPanel() = default;

private:
    void SetupUi() {

    }
};

#endif // CONTROLPANEL_H
