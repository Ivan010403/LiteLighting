#include "light_headers/fixture_array_delegates/universeaddressdelegate.h"

UniverseAddressDelegate::UniverseAddressDelegate(QWidget* parent) : QStyledItemDelegate(parent) {}

QWidget* UniverseAddressDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const {
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

void UniverseAddressDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {
    QSpinBox* spn_bx_universe = editor->findChild<QSpinBox*>();
    QSpinBox* spn_bx_address = editor->findChildren<QSpinBox*>()[1];

    QVariantList new_values;
    new_values << spn_bx_universe->value() << spn_bx_address->value();
    model->setData(index, new_values, Qt::EditRole);
}
