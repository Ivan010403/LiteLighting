#ifndef BUTTONVALUEPROPERTY_H
#define BUTTONVALUEPROPERTY_H

#include <QPushButton>
#include <QPainter>

class ButtonValueProperty : public QPushButton {
public:
    explicit ButtonValueProperty(const uint8_t* ptr_value, const bool* flag_command, const bool* flag_fixture, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void drawBackground(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);

    const uint8_t* ptr_value_;
    const bool* flag_command_;
    const bool* is_fixture_selected_;
};

#endif // BUTTONVALUEPROPERTY_H
