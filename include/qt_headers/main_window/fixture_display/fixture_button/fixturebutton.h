#ifndef FIXTUREBUTTON_H
#define FIXTUREBUTTON_H
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

#include <light_headers/Fixture.h>

class FixtureButton : public QPushButton {
Q_OBJECT

public:
    explicit FixtureButton(QPushButton* btn_parent_move, Fixture* fxt, QWidget* parent = nullptr) :
        QPushButton(parent),
        hold_timer_(new QTimer(this)),
        btn_parent_move_fixture_(btn_parent_move),
        fixture_under_btn_ (fxt)
    {
        this->setGeometry(20,20,100,100);
        this->setIcon(QIcon("/home/ivan/LiteLighting/res/spot.jpg"));
        this->setIconSize(QSize(100,100));
        this->show();

        hold_timer_->setInterval(1000);
        hold_timer_->setSingleShot(true);

        connect(hold_timer_, &QTimer::timeout, this, &FixtureButton::onHold);
    }

protected:
    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton)
        {
            hold_timer_->start();
        }
        QPushButton::mousePressEvent(event);

        // REFACTOR!!!
        emit sendFixtureId(fixture_under_btn_->getId());
        // REFACTOR!!!
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
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

signals:
    void sendFixtureId(unsigned int);

private slots:
    void onHold()
    {
        is_holded = true;
    }

private:
    bool is_holded = false;
    QTimer* hold_timer_;

    const QPushButton* btn_parent_move_fixture_;
    const Fixture* fixture_under_btn_;
};

#endif // FIXTUREBUTTON_H
