#ifndef QDIALOGGROUPING_H
#define QDIALOGGROUPING_H

#include <QDialog>

#include "light_headers/FixtureArray.h"

class QDialogGrouping : public QDialog {
Q_OBJECT

public:
    explicit QDialogGrouping(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);

signals:
    void GroupCreating(const QModelIndexList& selected_indexes, const QString& name);

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onBtnClicked();

private:
    void SetupUi(FixtureArrayModel* dmx_fixture_array);

    void SetupConnections();

    QVBoxLayout* vlayout_main_;
    QTableView* table_fixtures_;
    QLineEdit* line_edit_name_;
    QPushButton* btn_create_group_;

    QItemSelectionModel* selection_model_;
};

#endif // QDIALOGGROUPING_H
