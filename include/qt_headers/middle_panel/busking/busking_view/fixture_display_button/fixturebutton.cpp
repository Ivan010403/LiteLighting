#include "fixturebutton.h"

FixtureButton::FixtureButton(FixtureButton** selected_fixture_button, FixtureArrayModel* dmx_fixture_array, QPushButton* btn_parent_move, Fixture** selected_fixture, Fixture* fixture, int pos_x, int pos_y, QWidget* parent) :
    selected_fixture_button_(selected_fixture_button),
    dmx_fixture_array_(dmx_fixture_array),
    btn_parent_move_fixture_(btn_parent_move),
    selected_fixture_(selected_fixture),
    fixture_under_button_ (fixture),
    hold_timer_(new QTimer(this)),
    QPushButton(parent)
{
    hold_timer_->setInterval(1000);
    hold_timer_->setSingleShot(true);

    icon_ = QPixmap(":/photo/spotnobg.png");
    text_ = fixture_under_button_->name_;

    setGeometry(20,20,90,110);

    SetupConnections();

    show();

    move(pos_x, pos_y);
}

int FixtureButton::getPower() const {
    return fixture_under_button_->power_;
}

int FixtureButton::getFixId() const {
    return fixture_under_button_->GetFixtureId();
}

int FixtureButton::getPosX() const {
    return x();
}

int FixtureButton::getPosY() const {
    return y();
}

void FixtureButton::SelectedByGroup(int group_id) {
    isSelected = (fixture_under_button_->group_id_ == group_id);

    update();
}

void FixtureButton::PressedByFixture(int fixture_id) {
    isSelected = fixture_under_button_->GetFixtureId() == fixture_id ? true : false;

    update();
}

void FixtureButton::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawImage(painter);
    drawBorder(painter);
    drawText(painter);
}

void FixtureButton::mouseDoubleClickEvent(QMouseEvent* event) {
    if ((event->button() == Qt::LeftButton) && (fixture_under_button_->group_id_)) {
        (*selected_fixture_) = dmx_fixture_array_->GetFixtureByFixtureId(fixture_under_button_->group_id_*100);

        emit Mediator::instance().SelectingFixture();
        emit Mediator::instance().SelectingCommand();

        emit GroupChoosen(fixture_under_button_->group_id_);
    }
}

void FixtureButton::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
    {
        hold_timer_->start();

        (*selected_fixture_) = fixture_under_button_;
        emit Mediator::instance().SelectingFixture();
        emit Mediator::instance().SelectingCommand();

        (*selected_fixture_button_) = this;

        isPressed = true;
        isSelected = true;
        emit FixtureChoosen(fixture_under_button_->GetFixtureId());
    }
    QPushButton::mousePressEvent(event);
}

void FixtureButton::mouseReleaseEvent(QMouseEvent* event) {
    isPressed = false;

    if (event->button() == Qt::LeftButton)
    {
        hold_timer_->stop();
        is_holded = false;
    }
    QPushButton::mouseReleaseEvent(event);
}

void FixtureButton::mouseMoveEvent(QMouseEvent* event) {
    if (is_holded && btn_parent_move_fixture_->isChecked()) {
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

void FixtureButton::onHold() { is_holded = true; }

void FixtureButton::drawBackground(QPainter& painter) {
    QColor bgColor;

    bgColor = (isPressed || isSelected) ? QColor(59, 63, 64) : QColor(29, 33, 34);

    painter.setBrush(bgColor);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 11, 11);
}

void FixtureButton::drawImage(QPainter& painter) {
    QRect iconRect = rect().adjusted(0, 0, 0, -20);
    painter.drawPixmap(iconRect, icon_, icon_.rect());
}

void FixtureButton::drawBorder(QPainter& painter) {
    QPen pen;
    pen.setWidth(2);
    pen.setColor((isPressed || isSelected) ? QColor(118, 156, 227) : QColor(96, 102, 104));

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 8, 8);
}

void FixtureButton::drawText(QPainter& painter) {
    QRect textRect = rect().adjusted(10, height() - 30, -10, 0);

    QPen pen;
    pen.setColor((isPressed || isSelected) ? QColor(118, 156, 227) : QColor(255, 255, 255));

    painter.setPen(pen);
    painter.setFont(QFont("Arial", 10));
    painter.drawText(textRect, Qt::AlignCenter, text_);
}

void FixtureButton::SetupConnections() {
    connect(hold_timer_, &QTimer::timeout, this, &FixtureButton::onHold);
}
