#ifndef BUSKINGVIEW_H
#define BUSKINGVIEW_H

#include <QWidget>

#include "./fixture_display_button/fixturebutton.h"
#include "./fixture_display_button/socketbutton.h"
#include "./fixture_display_button/breakerbutton.h"

class BuskingView : public QWidget {
    Q_OBJECT
public:
    explicit BuskingView(FixtureArrayModel* dmx_fixture_array, Fixture** selected_fixture, QPushButton* btn_move, QWidget* parent = nullptr);

    ~BuskingView();

signals:
    void SelectingByGroup(int group_id);
    void PressingByFixture(int fix_id);

public slots:
    void onBtnAddClicked();
    void onBtnAddSocket();

    void onSocketPatched(FixtureButton*, SocketButton*, int);
    void onSocketUnpatched(FixtureButton*, SocketButton*, int);

    void SaveToShow();
    void LoadFromShow();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void SetupConnections();

    void CalculateElectricity();

    FixtureArrayModel* dmx_fixture_array_;
    Fixture** selected_fixture_;
    QPushButton* btn_move_;

    FixtureButton** selected_fixture_button_;

    QVector <FixtureButton*> qvect_fixture_buttons_;
    QVector <SocketButton*> qvect_socket_buttons_;

    std::map <SocketButton*, std::vector<FixtureButton*>> map_connected_fix_socket_;
};

#endif // BUSKINGVIEW_H
