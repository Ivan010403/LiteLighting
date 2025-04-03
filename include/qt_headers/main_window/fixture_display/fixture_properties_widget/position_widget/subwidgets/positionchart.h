#ifndef POSITIONCHART_H
#define POSITIONCHART_H
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

class PositionChart : public QWidget
{
    Q_OBJECT

public:
    explicit PositionChart (QWidget *parent = nullptr) : QWidget(parent) {

    }

    ~PositionChart() = default;

signals:
    void positionChanged(const QPoint position);

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(painter);

        drawGrid(painter);

        drawCurrentPosition(painter);
    }

    void mousePressEvent(QMouseEvent* event) override {
        if (event->buttons() & Qt::LeftButton) {
            QPoint clampedPos(qBound(0, event->pos().x(), width()), qBound(0, event->pos().y(), height()));
            m_position = clampedPos;
            update();
            emit positionChanged(clampedPos);
        }
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        if (event->buttons() & Qt::RightButton) { // изменить!
            QPoint clampedPos(qBound(0, event->pos().x(), width()), qBound(0, event->pos().y(), height()));
            m_position = clampedPos;
            update();
            emit positionChanged(clampedPos);
        }
    }

private:
    void drawBackground(QPainter& painter) {
        painter.fillRect(rect(), QColor(20, 40, 40));
    }

    void drawGrid(QPainter& painter) {
        painter.setPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine)); // изменить стиль

        // Вертикальные линии
        for(int x = m_gridSize; x < width(); x += m_gridSize) {
            painter.drawLine(x, 0, x, height());
        }

        // Горизонтальные линии
        for(int y = m_gridSize; y < height(); y += m_gridSize) {
            painter.drawLine(0, y, width(), y);
        }

        painter.setPen(QPen(QColor(80, 80, 80), 4, Qt::DotLine)); // изменить стиль
        painter.drawLine (width() / 2, 0, width()/2, height());
        painter.drawLine (0, height() / 2, width(), height()/2);

    }

    void drawCurrentPosition(QPainter& painter) {
        // Круг
        painter.setPen(QPen(Qt::cyan, 2));
        painter.drawEllipse(m_position, 8, 8);

        // Крест
        painter.drawLine(m_position.x() - 10, m_position.y(), m_position.x() + 10, m_position.y());
        painter.drawLine(m_position.x(), m_position.y() - 10, m_position.x(), m_position.y() + 10);
    }

    int m_gridSize = 10;
    QPoint m_position;
};

#endif // POSITIONCHART_H
