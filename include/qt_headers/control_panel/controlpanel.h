#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QPushButton>
#include <QStackedWidget>

#include "./stacked_widget_properties/stackedwidgetproperty.h"

class ControlPanel : public QWidget {
Q_OBJECT

public:
    explicit ControlPanel(AbstractCommand** main_command, Fixture** selected_fixture, QWidget* parent = nullptr);

    ~ControlPanel() = default;

private slots:
    void showDimmer();
    void showPosition();
    void showGobo();
    void showColor();
    void showBeam();
    void showFocus();
    void showControl();

private:
    void SetupUi(AbstractCommand** main_command, Fixture** selected_fixture);

    void SetupConnections();

    QVBoxLayout* vlayout_main_;

    QHBoxLayout* hlayout_btns_prpts_;
    QPushButton* btn_dimmer_;
    QPushButton* btn_position_;
    QPushButton* btn_gobo_;
    QPushButton* btn_color_;
    QPushButton* btn_beam_;
    QPushButton* btn_focus_;
    QPushButton* btn_control_;

    QStackedWidget* stacked_widget_properties_;
    StackedWidgetProperty* properties_dimmer_;
    StackedWidgetProperty* properties_position_;
    StackedWidgetProperty* properties_gobo_;
    StackedWidgetProperty* properties_color_;
    StackedWidgetProperty* properties_beam_;
    StackedWidgetProperty* properties_focus_;
    StackedWidgetProperty* properties_control_;


};

#endif // CONTROLPANEL_H
