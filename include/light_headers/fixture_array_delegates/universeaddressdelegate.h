#ifndef UNIVERSEADDRESSDELEGATE_H
#define UNIVERSEADDRESSDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>
#include <QHBoxLayout>
#include <QSpinBox>

// #include <QRegularExpressionValidator>
// #include <QRegularExpression>

#include <limits>

class UniverseAddressDelegate : public QStyledItemDelegate {
public:
    explicit UniverseAddressDelegate(QWidget* parent = nullptr) : QStyledItemDelegate(parent) {}

    ~UniverseAddressDelegate() = default;

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QWidget* editor = new QWidget(parent);
        QHBoxLayout* hlayout_main = new QHBoxLayout(editor);
        hlayout_main->setContentsMargins(0, 0, 0, 0);
        hlayout_main->setSpacing(0);

        QSpinBox* spn_bx_universe = new QSpinBox(editor);
        spn_bx_universe->setMinimum(1);
        spn_bx_universe->setMaximum(std::numeric_limits<uint16_t>::max() + 1);

        QSpinBox* spn_bx_address = new QSpinBox(editor);
        spn_bx_address->setMinimum(1);
        spn_bx_address->setMaximum(512);

        hlayout_main->addWidget(spn_bx_universe);
        hlayout_main->addWidget(spn_bx_address);

        return editor;
    }

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override {
        QSpinBox* spn_bx_universe = editor->findChild<QSpinBox*>();
        QSpinBox* spn_bx_address = editor->findChildren<QSpinBox*>()[1];

        QVariantList new_values;
        new_values << spn_bx_universe->value() << spn_bx_address->value();
        model->setData(index, new_values, Qt::EditRole);
    }
};

#endif // UNIVERSEADDRESSDELEGATE_H
