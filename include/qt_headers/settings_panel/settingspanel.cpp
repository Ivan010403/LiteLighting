#include "settingspanel.h"

SettingsPanel::SettingsPanel(QWidget* parent) : QWidget(parent) {
    pixmap_logo_.load(":/photo/logo.jpg");
    SetupUi();
}

void SettingsPanel::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QPainterPath path;
    QRect rect = QRect(7, 7, 66, 66);
    path.addRoundedRect(rect, 10, 10);

    painter.setClipPath(path);
    painter.drawPixmap(rect, pixmap_logo_);
}


void SettingsPanel::SetupUi() {
    setAttribute(Qt::WA_StyledBackground, true); // чтобы можно было красить фон
}
