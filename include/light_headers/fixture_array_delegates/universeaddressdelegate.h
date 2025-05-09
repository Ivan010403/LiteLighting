#ifndef UNIVERSEADDRESSDELEGATE_H
#define UNIVERSEADDRESSDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>
#include <QHBoxLayout>
#include <QSpinBox>

#include <limits>

class UniverseAddressDelegate : public QStyledItemDelegate {
public:
    explicit UniverseAddressDelegate(QWidget* parent = nullptr);

    ~UniverseAddressDelegate() = default;

    void setEditorData(QWidget* editor, const QModelIndex& index) const override;

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;
};

#endif // UNIVERSEADDRESSDELEGATE_H
