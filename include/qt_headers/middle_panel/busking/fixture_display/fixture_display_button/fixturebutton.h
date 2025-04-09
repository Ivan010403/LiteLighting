#ifndef FIXTUREBUTTON_H
#define FIXTUREBUTTON_H
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>

#include <light_headers/Fixture.h>

class FixtureButton : public QPushButton {
Q_OBJECT

public:
    explicit FixtureButton(QPushButton* btn_parent_move, unsigned int fixture_id, QWidget* parent = nullptr) :
        hold_timer_(new QTimer(this)),
        btn_parent_move_fixture_(btn_parent_move),
        fixture_id_ (fixture_id),
        QPushButton(parent)
    {
        setText(QString::number(fixture_id_));
        setGeometry(20,20,100,100);
        setIcon(QIcon("/home/ivan/LiteLighting/res/spot.jpg"));
        setIconSize(QSize(80,80));

        show();



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
        emit sendFixtureId(fixture_id_);
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
    unsigned int fixture_id_; // может быть конст?
};

#endif // FIXTUREBUTTON_H
