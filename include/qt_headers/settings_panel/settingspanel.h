#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class SettingsPanel : public QWidget {
    Q_OBJECT
public:
    explicit SettingsPanel(QWidget* parent = nullptr);

    ~SettingsPanel() = default;

private:
    void SetupUi();

    QVBoxLayout* vlayout_main_;
    QPushButton* btn_1;
    QPushButton* btn_2;
    QPushButton* btn_3;
    QPushButton* btn_4;
    QPushButton* btn_5;
    QPushButton* btn_6;
    QPushButton* btn_7;
    QPushButton* btn_8;
    QPushButton* btn_9;
};


#endif // SETTINGSPANEL_H
