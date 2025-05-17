#include "socketbutton.h"

SocketButton::SocketButton(FixtureButton** selected_fixture_button, QPushButton* btn_parent_move, QWidget* parent) :
    selected_fixture_button_(selected_fixture_button),
    btn_parent_move_(btn_parent_move),
    hold_timer_(new QTimer(this)),
    QPushButton(parent)
{
    hold_timer_->setInterval(1000);
    hold_timer_->setSingleShot(true);

    qdial_command_ = new QDialogSocket(this);

    connect(hold_timer_, &QTimer::timeout, this, &SocketButton::onHold);
    connect(qdial_command_, &QDialogSocket::SaveClicked, this, &SocketButton::onSaveClicked);

    setGeometry(20, 20, 60, 70);

    show();
}

int SocketButton::getBreaker() const {
    return breaker_number_;
}

void SocketButton::mouseDoubleClickEvent(QMouseEvent* event) {
    if ((event->button() == Qt::LeftButton) && (*selected_fixture_button_) && (breaker_number_ != 0) && ((*selected_fixture_button_)->socket_number == 0)) {
        (*selected_fixture_button_)->socket_number = breaker_number_;
        emit SocketPatching(*selected_fixture_button_, this, breaker_number_);
    }
    else if ((event->button() == Qt::RightButton) && (*selected_fixture_button_) && (breaker_number_ != 0) && ((*selected_fixture_button_)->socket_number == breaker_number_)) {
        (*selected_fixture_button_)->socket_number = 0;
        emit SocketUnpatching(*selected_fixture_button_, this, breaker_number_);
    }
}

void SocketButton::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        hold_timer_->start();
    }
    else if ((event->button() == Qt::RightButton) && (breaker_number_ == 0)) {
        qdial_command_->exec();
    }
    QPushButton::mousePressEvent(event);
}

void SocketButton::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
    {
        hold_timer_->stop();
        is_holded = false;
    }
    QPushButton::mouseReleaseEvent(event);
}

void SocketButton::mouseMoveEvent(QMouseEvent* event) {
    if (is_holded && btn_parent_move_->isChecked()) {
        QPoint currentPos = parentWidget()->mapFromGlobal(event->globalPosition().toPoint());
        QPoint delta = currentPos - this->pos();
        QPoint newPos = this->pos() + delta;

        int maxX = qMax(0, parentWidget()->width() - width());
        int maxY = qMax(0, parentWidget()->height() - height());

        newPos.setX(qBound(0, newPos.x(), maxX));
        newPos.setY(qBound(0, newPos.y(), maxY));

        this->move(newPos);
    }
}

void SocketButton::onHold() { is_holded = true; }

void SocketButton::onSaveClicked(int value) {
    if (CircuitBreaker::instance().isExisting(value - 1)) {
        breaker_number_ = value;

        switch(CircuitBreaker::instance().getPhase(breaker_number_ - 1)) {
        case 1:
            main_color_ = QColor(Qt::red);
            break;
        case 2:
            main_color_ = QColor(Qt::green);
            break;
        case 3:
            main_color_ = QColor(Qt::blue);
            break;
        }
    }
}

void SocketButton::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawImage(painter);
    drawBorder(painter);
    drawText(painter);
}

void SocketButton::drawImage(QPainter& painter) {
    painter.drawPixmap(rect().adjusted(5, 5, -5, -15), icon_, icon_.rect());
}

void SocketButton::drawBorder(QPainter& painter) {
    QPen pen;
    pen.setWidth(2);
    pen.setColor(main_color_);

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 8, 8);
}

void SocketButton::drawText(QPainter& painter) {
    QRect textRect = rect().adjusted(0, height() - 17, 0, 0);

    QPen pen;
    pen.setColor(main_color_);

    painter.setPen(pen);
    painter.setFont(QFont("Arial", 7));
    painter.drawText(textRect, Qt::AlignCenter, "Break №" + QString::number(breaker_number_));
}


