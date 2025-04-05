#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class SettingsPanel : public QWidget {
Q_OBJECT

public:
    explicit SettingsPanel(QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~SettingsPanel() = default;

private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(15, 15, 15, 15);
        btn_1 = new QPushButton(this);
        btn_2 = new QPushButton(this);
        btn_3 = new QPushButton(this);
        btn_4 = new QPushButton(this);
        btn_5 = new QPushButton(this);
        btn_6 = new QPushButton(this);
        btn_7 = new QPushButton(this);
        btn_8 = new QPushButton(this);
        btn_9 = new QPushButton(this);
        btn_1->setFixedSize(50, 50);
        btn_2->setFixedSize(50, 50);
        btn_3->setFixedSize(50, 50);
        btn_4->setFixedSize(50, 50);
        btn_5->setFixedSize(50, 50);
        btn_6->setFixedSize(50, 50);
        btn_7->setFixedSize(50, 50);
        btn_8->setFixedSize(50, 50);
        btn_9->setFixedSize(50, 50);
        vlayout_main_->addWidget(btn_1);
        vlayout_main_->addWidget(btn_2);
        vlayout_main_->addWidget(btn_3);
        vlayout_main_->addWidget(btn_4);
        vlayout_main_->addWidget(btn_5);
        vlayout_main_->addWidget(btn_6);
        vlayout_main_->addWidget(btn_7);
        vlayout_main_->addWidget(btn_8);
        vlayout_main_->addWidget(btn_9);
        vlayout_main_->setSpacing(20);
    }

    QVBoxLayout* vlayout_main_;
    QPushButton* btn_1;
    QPushButton* btn_2;
    QPushButton* btn_3;
    QPushButton* btn_4;
    QPushButton* btn_5;
    QPushButton* btn_6;
    QPushButton* btn_7;
    QPushButton* btn_8;
    QPushButton* btn_9;
};


#endif // SETTINGSPANEL_H
