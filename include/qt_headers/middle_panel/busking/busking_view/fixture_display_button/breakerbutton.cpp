#include "breakerbutton.h"

BreakerButton::BreakerButton(QWidget* parent) : QWidget(parent) {
    connect(&CircuitBreaker::instance(), &CircuitBreaker::UploadingData, this, &BreakerButton::onUploadedData);

    SetupUi();
}

void BreakerButton::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int x_100_1 = vect_breakers_[0]->x() + (vect_breakers_[0]->rect().width() / 5);
    int x_100_2 = vect_breakers_[0]->x() + (vect_breakers_[0]->rect().width() / 2);
    int x_100_3 = vect_breakers_[0]->x() + (vect_breakers_[0]->rect().width() / 2) + (vect_breakers_[0]->rect().width() / 4);

    for (int i = 1; i < vect_breakers_.size(); ++i) {
        switch (CircuitBreaker::instance().getPhase(i - 1)) {
        case 1: {
            QPainterPath path;

            path.moveTo(x_100_1, vect_breakers_[0]->y());
            path.lineTo(x_100_1, vect_breakers_[0]->y()-30);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y()-30);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y());

            QPen pen(Qt::red, 2);
            painter.setPen(pen);
            painter.drawPath(path);

            break;
        }
        case 2: {
            QPainterPath path;

            path.moveTo(x_100_2, vect_breakers_[0]->y());
            path.lineTo(x_100_2, vect_breakers_[0]->y()-20);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y()-20);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y());

            QPen pen(Qt::green, 2);
            painter.setPen(pen);
            painter.drawPath(path);
            break;
        }
        case 3: {
            QPainterPath path;

            path.moveTo(x_100_3, vect_breakers_[0]->y());
            path.lineTo(x_100_3, vect_breakers_[0]->y()-10);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y()-10);
            path.lineTo(vect_breakers_[i]->x() + vect_breakers_[i]->width() / 2, vect_breakers_[0]->y());

            QPen pen(Qt::blue, 2);
            painter.setPen(pen);
            painter.drawPath(path);
            break;
        }
        default:
            break;
        }
    }
}

void BreakerButton::onUploadedData() {
    for (int i = vect_breakers_.size() - 1; i < CircuitBreaker::instance().size(); ++i) {
        QLabel* c16 = new QLabel(this);
        c16->setFixedSize(26, 100);
        c16->setPixmap(pixmap_C16_);
        c16->setScaledContents(true);

        if (hlayout_main_->count() > 1) {
            QLayoutItem* last = hlayout_main_->takeAt(hlayout_main_->count()-1);

            if (last->spacerItem()) delete last->spacerItem();
        }

        hlayout_main_->addWidget(c16);
        hlayout_main_->addStretch();

        vect_breakers_.push_back(c16);
    }
}

void BreakerButton::SetupUi() {
    setFixedHeight(166);

    hlayout_main_ = new QHBoxLayout(this);
    hlayout_main_->setContentsMargins(0, 0, 0, 0);
    hlayout_main_->setSpacing(0);

    QLabel* c100 = new QLabel(this);
    c100->setFixedSize(105, 100);
    c100->setPixmap(pixmap_C100_);
    c100->setScaledContents(true);

    if (hlayout_main_->count() == 0) hlayout_main_->addStretch();
    hlayout_main_->addWidget(c100);
    hlayout_main_->addStretch();

    vect_breakers_.push_back(c100);
}
