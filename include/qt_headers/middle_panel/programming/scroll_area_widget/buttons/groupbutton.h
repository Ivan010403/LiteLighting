#ifndef GROUPBUTTON_H
#define GROUPBUTTON_H

#include <QMouseEvent>
#include <QPainter>

#include "./modal_windows/qdialoggrouping.h"
#include "./modal_windows/qdialogeditor.h"
#include "light_headers/FixtureGroup.h"


class GroupButton : public QPushButton {
    Q_OBJECT
public:
    explicit GroupButton(Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, int number, const int* ptr, QWidget* parent = nullptr);

    ~GroupButton();

signals:
    void onEndedButtons();

protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;

private slots:
    void OnGroupCreated(const QModelIndexList& selected_indexes, const QString& name);
    void OnGroupCreatedMediator(int, Fixture*, const QString&);
    void OnDeleteFixture(Fixture*);

    void onDeleteCurrent();

private:
    void SetupUi();

    void SetupConnections();

    void drawBackground(QPainter& painter);

    void drawBorder(QPainter& painter);

    void drawText(QPainter& painter);

private:
    Fixture** selected_fixture_;
    FixtureArrayModel* dmx_fixture_array_;
    const int number_;
    const int* ptr_current_amount_;

    Fixture* group_ = nullptr;

    QDialogGrouping* qdial_grouping_;
    QDialogEditor* qdial_editor_;
};

#endif // GROUPBUTTON_H
