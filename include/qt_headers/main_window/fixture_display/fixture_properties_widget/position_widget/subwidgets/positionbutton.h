#ifndef POSITIONBUTTON_H
#define POSITIONBUTTON_H
#include <QPushButton>
#include <QString>
#include <QPaintEvent>

class PositionButton : public QWidget {
    Q_OBJECT
public:
    explicit PositionButton (const QString& name, QWidget *parent = nullptr) : QWidget(parent) {

    }

    ~PositionButton() = default;

protected:
    // void paintEvent(QPaintEvent* event) {

    // }
private:

};

#endif // POSITIONBUTTON_H
