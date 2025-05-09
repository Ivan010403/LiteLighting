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
    explicit FixtureButton(FixtureArrayModel* dmx_fixture_array, QPushButton* btn_parent_move, Fixture** selected_fixture, Fixture* fixture, QWidget* parent = nullptr) :
        dmx_fixture_array_(dmx_fixture_array),
        btn_parent_move_fixture_(btn_parent_move),
        selected_fixture_(selected_fixture),
        fixture_under_button_ (fixture),
        hold_timer_(new QTimer(this)),
        QPushButton(parent)
    {
        hold_timer_->setInterval(1000);
        hold_timer_->setSingleShot(true);

        icon_ = QPixmap("/home/ivan/LiteLighting/res/spot.jpg");
        text_ = fixture_under_button_->name_;

        setGeometry(20,20,90,110);

        SetupConnections();

        show();
    }

signals:
    void GroupChoosen(int);
    void FixtureChoosen(int);

public slots:
    void SelectedByGroup(int group_id) {
        isSelected = (fixture_under_button_->group_id_ == group_id);

        update();
    }

    void PressedByFixture(int fixture_id) {
        isSelected = fixture_under_button_->GetFixtureId() == fixture_id ? true : false;

        update();
    }

protected:
    void paintEvent(QPaintEvent* event) {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(painter);
        drawImage(painter);
        drawBorder(painter);
        drawText(painter);
    }

    void mouseDoubleClickEvent(QMouseEvent* event) override {
        if ((event->button() == Qt::LeftButton) && (fixture_under_button_->group_id_)) {
            (*selected_fixture_) = dmx_fixture_array_->GetFixtureByFixtureId(fixture_under_button_->group_id_*100);

            emit Mediator::instance().SelectingFixture();
            emit Mediator::instance().SelectingCommand();

            emit GroupChoosen(fixture_under_button_->group_id_);
        }
    }

    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton)
        {
            hold_timer_->start();

            (*selected_fixture_) = fixture_under_button_;
            emit Mediator::instance().SelectingFixture();
            emit Mediator::instance().SelectingCommand();

            isPressed = true;
            isSelected = true;
            emit FixtureChoosen(fixture_under_button_->GetFixtureId());
        }
        QPushButton::mousePressEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        isPressed = false;

        if (event->button() == Qt::LeftButton)
        {
            hold_timer_->stop();
            is_holded = false;
        }
        QPushButton::mouseReleaseEvent(event);
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        if (is_holded && btn_parent_move_fixture_->isChecked()) {
            this->move(QPoint(this->pos() + event->pos()));
        }
    }

private slots:
    void onHold() { is_holded = true; }

private:
    void drawBackground(QPainter& painter) {
        QColor bgColor;

        bgColor = (isPressed || isSelected) ? QColor(59, 63, 64) : QColor(29, 33, 34);

        painter.setBrush(bgColor);
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(rect(), 11, 11);
    }

    void drawImage(QPainter& painter) {
        QRect iconRect = rect().adjusted(8, 8, -8, -28);
        painter.drawPixmap(iconRect, icon_, icon_.rect());
    }

    void drawBorder(QPainter& painter) {
        QPen pen;
        pen.setWidth(2);
        pen.setColor((isPressed || isSelected) ? QColor(118, 156, 227) : QColor(96, 102, 104));

        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 8, 8);
    }

    void drawText(QPainter& painter) {
        QRect textRect = rect().adjusted(10, height() - 30, -10, 0);

        QPen pen;
        pen.setColor((isPressed || isSelected) ? QColor(118, 156, 227) : QColor(255, 255, 255));

        painter.setPen(pen);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(textRect, Qt::AlignCenter, text_);
    }

    void SetupConnections() {
        connect(hold_timer_, &QTimer::timeout, this, &FixtureButton::onHold);
    }

    FixtureArrayModel* dmx_fixture_array_;
    const QPushButton* btn_parent_move_fixture_;

    Fixture** selected_fixture_;
    Fixture* fixture_under_button_; // может быть конст?

    QTimer* hold_timer_;

    bool is_holded = false;
    bool isSelected = false;
    bool isPressed = false;

    QPixmap icon_;
    QString text_;
};

#endif // FIXTUREBUTTON_H
