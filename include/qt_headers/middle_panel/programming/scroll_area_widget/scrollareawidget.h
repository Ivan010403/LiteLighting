#ifndef SCROLLAREAWIDGET_H
#define SCROLLAREAWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QScrollBar>

#include "./buttons/typebutton.h"
#include "./buttons/programmingbutton.h"

class ScrollAreaWidget : public QWidget {
Q_OBJECT

public:
    explicit ScrollAreaWidget(AbstractCommand** main_command, ProgrammingType scrl_area_type, QWidget* parent = nullptr) :
        main_command_(main_command),
        type_channels_(scrl_area_type),
        QWidget(parent)
    {
        columns_per_row_ = (scrl_area_type == ProgrammingType::Group || scrl_area_type == ProgrammingType::Default) ? 20 : 10;

        batch_size_ = (scrl_area_type == ProgrammingType::Group || scrl_area_type == ProgrammingType::Default ||
                       scrl_area_type == ProgrammingType::Focus || scrl_area_type == ProgrammingType::Beam ) ? 40 : 50;

        SetupUi();
        SetupConnections();
        AddButtons(batch_size_);

    }

    ~ScrollAreaWidget() = default;

private:
    void SetupUi() {
        gridlayout_main_ = new QGridLayout(this);
        gridlayout_main_->setContentsMargins(16, 16, 10, 16);
        gridlayout_main_->setSpacing(15);
    }

    void SetupConnections() {

    }

    void AddButtons(int count) {
        TypeButton* button = new TypeButton(type_channels_, this);
        button->setFixedSize(button_size_, button_size_);
        gridlayout_main_->addWidget(button, 0, 0);

        for (int i = 1; i < count; ++i) {
            ProgrammingButton* button = new ProgrammingButton(main_command_, type_channels_, this);
            button->setFixedSize(button_size_, button_size_);

            // Рассчитываем позицию в сетке
            int row = current_count_ / columns_per_row_;
            int column = current_count_ % columns_per_row_;

            gridlayout_main_->addWidget(button, row, column);
            ++current_count_;
        }

        // Обновляем размер контента
        adjustSize();
    }

    QGridLayout* gridlayout_main_;

    AbstractCommand** main_command_;
    ProgrammingType type_channels_;
    int current_count_ = 1;
    int columns_per_row_;

    const int button_size_ = 60;
    int batch_size_;
};

#endif // SCROLLAREAWIDGET_H
