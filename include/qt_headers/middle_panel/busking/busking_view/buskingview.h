#ifndef BUSKINGVIEW_H
#define BUSKINGVIEW_H

#include <QWidget>

#include "./fixture_display_button/fixturebutton.h"

class BuskingView : public QWidget {
    Q_OBJECT
public:
    explicit BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent = nullptr);

    ~BuskingView() = default;

signals:
    void SelectingByGroup(int group_id);
    void PressingByFixture(int fix_id);

public slots:
    void onBtnAddClicked();

private:
    FixtureArrayModel* dmx_fixture_array_;
    Fixture** selected_fixture_;
    QPushButton* btn_move_;

    QVector <FixtureButton*> qvect_fixture_buttons_;
};

#endif // BUSKINGVIEW_H

// connect(btn_add_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnAddClicked);
// connect(btn_delete_fixture_, &QPushButton::clicked, busking_view_, &BuskingView::onBtnDelClicked);
