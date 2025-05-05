#ifndef GROUPBUTTON_H
#define GROUPBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>

#include "./modal_windows/qdialoggrouping.h"
#include "light_headers/FixtureGroup.h"

class GroupButton : public QPushButton {
    Q_OBJECT
public:
    explicit GroupButton(Fixture** selected_fixture, FixtureArrayModel* dmx_fixture_array, int number, QWidget* parent = nullptr);

    ~GroupButton();

protected:
    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;

private slots:
    void OnGroupCreated(const QModelIndexList& selected_indexes, const QString& name);
    void OnGroupCreatedMediator(int, Fixture*);

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

    Fixture* group_ = nullptr;

    QDialogGrouping* qdial_grouping_;
};

#endif // GROUPBUTTON_H
