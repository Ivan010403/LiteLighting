#ifndef BREAKERBUTTON_H
#define BREAKERBUTTON_H

#include <QLabel>
#include <QPainter>
#include <QPainterPath>

#include "light_headers/CircuitBreaker.h"

class BreakerButton : public QWidget {
public:
    explicit BreakerButton(QWidget* parent = nullptr);

    ~BreakerButton() = default;

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void onUploadedData();

private:
    void SetupUi();

    QHBoxLayout* hlayout_main_;
    std::vector <QLabel*> vect_breakers_;

    const QPixmap pixmap_C100_ = QPixmap(":/photo/C100.png");
    const QPixmap pixmap_C16_ = QPixmap(":/photo/C16.png");
};

#endif // BREAKERBUTTON_H
