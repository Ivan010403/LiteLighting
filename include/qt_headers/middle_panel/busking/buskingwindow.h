#ifndef BUSKINGWINDOW_H
#define BUSKINGWINDOW_H

#include <QWidget>
#include <QPushButton>

#include "./busking_view/buskingview.h"

class BuskingWindow : public QWidget {
public:
    explicit BuskingWindow(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QWidget* parent = nullptr);

    ~BuskingWindow() = default;


private:
    void SetupUi(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture);

    void SetupConnections();

    QGridLayout* gridlayout_main_;

    QPushButton* btn_add_fixture_;
    QPushButton* btn_move_fixture_;
    QPushButton* btn_add_socket_;

    BuskingView* busking_view_;

    BreakerButton* btn_breaker_;
};

#endif // BUSKINGWINDOW_H
