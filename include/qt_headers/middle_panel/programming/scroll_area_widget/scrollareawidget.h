#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollBar>

#include <QDialog> // убрать

#include "light_headers/ChannelTypeEnum.h"

class ScrollAreaWidget : public QWidget {
Q_OBJECT

public:
    explicit ScrollAreaWidget(ProgrammingType scrl_area_type, QScrollBar* parent_scrollbar,  QWidget* parent = nullptr) :
        type_channels_(scrl_area_type),
        parent_scrollbar_(parent_scrollbar),
        columns_per_row_(5), // заменить!!!
        QWidget(parent)
    {
        SetupUi();
        SetupConnections();
        AddButtons(batch_size_);

    }

    ~ScrollAreaWidget() = default;

private slots:
    void onScroll(int value) {
        int current = parent_scrollbar_->value();

        // Проверяем, достигли ли мы нижней границы
        if (current + parent_scrollbar_->height() >= this->height() - threshold_) {
            AddButtons(batch_size_);
        }
    }

    // void handleButtonClick(int index) {
    //     qDebug() << "Button clicked:" << index;
    // }

private:
    void SetupUi() {
        gridlayout_main_ = new QGridLayout(this);
        gridlayout_main_->setContentsMargins(0, 0, 0, 0);
        gridlayout_main_->setSpacing(12);
    }

    void SetupConnections() {
        connect(parent_scrollbar_, &QScrollBar::valueChanged, this, &ScrollAreaWidget::onScroll);
    }

    void AddButtons(int count) {
        for (int i = 0; i < count; ++i) {
            QPushButton* button = new QPushButton(QString::number(current_count_ + 1), this);
            button->setFixedSize(button_size_, button_size_);

            // Рассчитываем позицию в сетке
            int row = current_count_ / columns_per_row_;
            int column = current_count_ % columns_per_row_;

            // connect(button, &QPushButton::clicked, this, &ScrollAreaWidget::onClick);

            gridlayout_main_->addWidget(button, row, column);
            ++current_count_;
        }

        // Обновляем размер контента
        adjustSize();
    }

    QScrollBar* parent_scrollbar_;
    QGridLayout* gridlayout_main_;

    ProgrammingType type_channels_;
    int current_count_ = 0;
    const int columns_per_row_;
    const int button_size_ = 60;
    const int batch_size_ = 40;
    const int threshold_ = 100;

};

#endif // SCROLLAREAWIDGET_H
