#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <QPainterPath>

#include "light_headers/FixtureArray.h"
#include "light_headers/programming_command/CommandArray.h"
#include "light_headers/CircuitBreaker.h"

class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    explicit SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr);
    ~SettingsWindow() = default;

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void onLoadClicked();

    void onSaveClicked();

    void onEnteringData(int value);

    void onSetupClicked();

private:
    void PaintElectrPerAutomat(QPainter& painter);
    void PaintTotal(QPainter& painter);
    void PaintElectrPerPhase(QPainter& painter);

    void SetupUi();

    void SetupConnections();

    FixtureArrayModel* dmx_fixture_array_;

    QGridLayout* gridlayout_main_;
    QPushButton* btn_load_showfile_;
    QPushButton* btn_save_showfile_;

    QLabel* label_amperage_;
    QSpinBox* spnbox_edit_amperage_;

    QLabel* label_amount_;
    QSpinBox* spnbox_edit_amount_;

    QHBoxLayout* hlayout_patching_;

    QWidget* for_painting_;

    QPushButton* btn_setup_electrical_;

    const QPixmap pixmap_C100_ = QPixmap(":/photo/C100.png");
    const QPixmap pixmap_C16_ = QPixmap(":/photo/C16.png");

};
#endif // SETTINGSWINDOW_H
