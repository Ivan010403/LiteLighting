#ifndef FIXTUREDISPLAY_H
#define FIXTUREDISPLAY_H
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


#include "light_headers/FixtureArray.h"

class FixtureDisplay : public QFrame {
Q_OBJECT

public:
    explicit FixtureDisplay(QWidget* parent = nullptr) : QFrame(parent) {
        Setup();
        SetupConnections();
    }
    ~FixtureDisplay() {}

    void setFixtureArray(FixtureArray* fxt_arr) {
        dmx_fixture_array_ = fxt_arr;
    }

    void Setup() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(0, 0, 0, 0);

        hlayout_btns_ = new QHBoxLayout();
        hlayout_btns_->setSpacing(40);

        btn_add_fixture_ = new QPushButton("Add fixture", this);
        btn_add_fixture_->setEnabled(true);

        btn_move_fixture_ = new QPushButton("Move fixture", this);
        btn_move_fixture_->setEnabled(true);

        hlayout_btns_->addWidget(btn_add_fixture_);
        hlayout_btns_->addWidget(btn_move_fixture_);
        hlayout_btns_->setStretch(0, 1);
        hlayout_btns_->setStretch(1, 1);

        qframe_display_ = new QFrame(this);

        vlayout_main_->addLayout(hlayout_btns_);
        vlayout_main_->addWidget(qframe_display_);
        vlayout_main_->setStretch(0,1);
        vlayout_main_->setStretch(1,4);
    }

    void SetupConnections() {
        connect(btn_add_fixture_, &QPushButton::clicked, this, &FixtureDisplay::OnBtnAddClicked);
    }

signals:
    void FixtureChoosen();

private slots:
    void OnBtnAddClicked() {
        qDebug() << "btn added";
        test = new QPushButton("Test", qframe_display_);
        test->setGeometry(200,200, 200,200);
        test->setEnabled(true);
        test->show();

        connect(test, &QPushButton::clicked, this, &FixtureDisplay::FixtureChoosen);
    }
// protected:
//     void paintEvent(QPaintEvent *event) {
//         QGroupBox::paintEvent(event);

//         // Создаем объект QPainter для рисования
//         QPainter painter(this);

//         // Пример: Рисуем рамку вокруг QGroupBox
//         painter.setPen(Qt::red); // Устанавливаем цвет пера
//         painter.drawRect(this->rect().adjusted(0, 0, -1, -1)); // Рисуем прямоугольник

//         // Пример: Рисуем текст в центре QGroupBox
//         painter.setPen(Qt::blue); // Устанавливаем цвет текста
//         painter.drawText(this->rect(), Qt::AlignCenter, "Custom Paint");
//     }


private:
    QVBoxLayout* vlayout_main_;
    QHBoxLayout* hlayout_btns_;
    QPushButton* btn_add_fixture_;
    QPushButton* btn_move_fixture_;
    QFrame* qframe_display_;

    QPushButton* test;


    FixtureArray* dmx_fixture_array_;
};

#endif // FIXTUREDISPLAY_H
