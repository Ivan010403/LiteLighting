#ifndef PAGESBUTTON_H
#define PAGESBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QPainterPath>

class PagesButton : public QPushButton {
public:
    explicit PagesButton(const QString& path, const QString& text, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap pixmap_backgrnd_image_;
};

#endif // PAGESBUTTON_H
