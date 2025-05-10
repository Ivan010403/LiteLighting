#include "pagesbutton.h"

PagesButton::PagesButton(const QString& path, const QString& text, QWidget* parent) : QPushButton(text, parent) {
    pixmap_backgrnd_image_.load(path);
}

void PagesButton::paintEvent(QPaintEvent* event) {
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QPainterPath path;
    path.addRoundedRect(rect(), 20, 20);

    painter.setClipPath(path);
    painter.setOpacity(0.2);
    painter.drawPixmap(rect(), pixmap_backgrnd_image_);
}
