#ifndef GROUPBUTTON_H
#define GROUPBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>

#include "./modal_windows/qdialoggrouping.h"
#include "light_headers/FixtureGroup.h"

class GroupButton : public QPushButton {
Q_OBJECT

public:
    explicit GroupButton(Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, int number, QWidget* parent = nullptr) :
        selected_fixture_(selected_fixture),
        dmx_fixture_array_(dmx_fixture_array),
        number_(number),
        QPushButton(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~GroupButton() {
        delete group_; // опасно!
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(painter);
        drawBorder(painter);
        drawText(painter);
    }

    void mousePressEvent(QMouseEvent* event) override {
        if ((event->button() == Qt::RightButton) && (!group_)) {
            if (qdial_grouping_->exec() == QDialog::Accepted) {
                qDebug() << "конец работы модального окна!!!";
            }
        } else {
            QPushButton::mousePressEvent(event);
        }
    }

    void mouseDoubleClickEvent(QMouseEvent* event) override {
        if ((event->button() == Qt::LeftButton) && (group_)) {
            if (group_) {
                (*selected_fixture_) = group_;
            }
        }
        // Вызываем базовую реализацию (если нужно)
        // QPushButton::mouseDoubleClickEvent(event);
    }

private slots:
    void OnGroupCreated(const QModelIndexList& selected_indexes) {
        QSet<int> unique_rows;
        for (const QModelIndex& index : selected_indexes) {
            if (index.isValid()) {
                unique_rows.insert(index.row());
            }
        }

        std::vector<Fixture*> vect_fxtr;

        for (const int var : unique_rows) {
            vect_fxtr.push_back(dmx_fixture_array_->GetFixtureByIndex(var));
        }

        group_ = new FixtureGroup(number_, "test", vect_fxtr);

        setText(QString::number(number_));
    }

private:
    void SetupUi() {
        setFixedSize(60, 60);

        qdial_grouping_ = new QDialogGrouping(dmx_fixture_array_, this);
    }

    void SetupConnections() {
        connect(qdial_grouping_, &QDialogGrouping::GroupCreating, this, &GroupButton::OnGroupCreated);
    }

    void drawBackground(QPainter& painter) {
        QBrush brush (QColor(29, 33, 34));

        if (isDown()) {
            brush.setColor(QColor(59, 63, 64));
        }

        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), 10, 10);
    }

    void drawBorder(QPainter& painter) {
        QPen pen(QColor(96, 102, 104));

        if (isDown()) {
            pen.setColor(QColor(118, 156, 227));
        }

        pen.setWidth(2);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(rect().adjusted(1, 1, -1, -1), 10, 10);
    }

    void drawText(QPainter& painter) {
        QFont new_font = font();
        new_font.setPointSize(8);

        painter.setPen(Qt::white);
        painter.setFont(new_font);
        painter.drawText(rect().adjusted(20, 10, 0, 0), Qt::AlignLeft, QString::number(number_));
        painter.drawText(rect().adjusted(0, 25, 0, 0), Qt::TextWordWrap | Qt::AlignCenter, text());
    }


private:
    Fixture** selected_fixture_;
    FixtureArrayModel* dmx_fixture_array_;
    const int number_;

    Fixture* group_ = nullptr;


    QDialogGrouping* qdial_grouping_;
};

#endif // GROUPBUTTON_H
