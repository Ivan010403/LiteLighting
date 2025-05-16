#ifndef SOCKETBUTTON_H
#define SOCKETBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

#include "light_headers/CircuitBreaker.h"
#include "light_headers/Fixture.h"
#include "./modal_window/qdialogsocket.h"
#include "fixturebutton.h"

class SocketButton : public QPushButton {
    Q_OBJECT
public:
    explicit SocketButton(FixtureButton** selected_fixture_button, QPushButton* btn_parent_move, QWidget* parent = nullptr);

    int getBreaker() const;

signals:
    void SocketPatching(FixtureButton*, SocketButton*, int);
    void SocketUnpatching(FixtureButton*, SocketButton*, int);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private slots:
    void onHold();
    void onSaveClicked(int);

private:
    void drawImage(QPainter& painter);
    void drawBorder(QPainter& painter);
    void drawText(QPainter& painter);

    FixtureButton** selected_fixture_button_;
    QPushButton* btn_parent_move_;
    QTimer* hold_timer_;

    int breaker_number_ = 0;
    bool is_holded = false;

    QPixmap icon_ = QPixmap(":/photo/socket.png");
    QColor main_color_ = QColor(118, 156, 227);

    QDialogSocket* qdial_command_;
};

#endif // SOCKETBUTTON_H
