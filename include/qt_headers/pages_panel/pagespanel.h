#ifndef PAGESPANEL_H
#define PAGESPANEL_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class PagesPanel : public QWidget {
Q_OBJECT

public:
    explicit PagesPanel(QWidget* parent = nullptr) : QWidget(parent) {
        SetupUi();
    }

    ~PagesPanel() = default;

private:
    void SetupUi() {
        vlayout_main_ = new QVBoxLayout(this);
        vlayout_main_->setContentsMargins(10, 30, 10, 40);
        btn_page_1 = new QPushButton(this);
        btn_page_2 = new QPushButton(this);
        btn_page_3 = new QPushButton(this);
        btn_page_4 = new QPushButton(this);
        btn_page_5 = new QPushButton(this);
        btn_page_1->setFixedSize(200, 100);
        btn_page_2->setFixedSize(200, 100);
        btn_page_3->setFixedSize(200, 100);
        btn_page_4->setFixedSize(200, 100);
        btn_page_5->setFixedSize(200, 100);
        vlayout_main_->addWidget(btn_page_1);
        vlayout_main_->addWidget(btn_page_2);
        vlayout_main_->addWidget(btn_page_3);
        vlayout_main_->addWidget(btn_page_4);
        vlayout_main_->addWidget(btn_page_5);
        vlayout_main_->setSpacing(40);
    }

    QVBoxLayout* vlayout_main_;
    QPushButton* btn_page_1;
    QPushButton* btn_page_2;
    QPushButton* btn_page_3;
    QPushButton* btn_page_4;
    QPushButton* btn_page_5;
};

#endif // PAGESPANEL_H
