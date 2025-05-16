#ifndef FIXTUREBUTTON_H
#define FIXTUREBUTTON_H

#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

#include "light_headers/FixtureArray.h"
#include "light_headers/Mediator.h"

class FixtureButton : public QPushButton {
    Q_OBJECT
public:
    explicit FixtureButton(FixtureButton** selected_fixture_button, FixtureArrayModel* dmx_fixture_array, QPushButton* btn_parent_move, Fixture** selected_fixture, Fixture* fixture, int pos_x, int pos_y, QWidget* parent = nullptr);

    int getFixId() const;
    int getPosX() const;
    int getPosY() const;

    int socket_number = 0;

signals:
    void GroupChoosen(int);
    void FixtureChoosen(int);

public slots:
    void SelectedByGroup(int group_id);

    void PressedByFixture(int fixture_id);

protected:
    void paintEvent(QPaintEvent* event) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

private slots:
    void onHold();

private:
    void drawBackground(QPainter& painter);

    void drawImage(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);

    void SetupConnections();

    FixtureArrayModel* dmx_fixture_array_;
    const QPushButton* btn_parent_move_fixture_;

    Fixture** selected_fixture_;
    Fixture* fixture_under_button_; // может быть конст?

    FixtureButton** selected_fixture_button_;

    QTimer* hold_timer_;

    bool is_holded = false;
    bool isSelected = false;
    bool isPressed = false;

    QPixmap icon_;
    QString text_;
};

#endif // FIXTUREBUTTON_H
