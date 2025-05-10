#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>

class SettingsPanel : public QWidget {
    Q_OBJECT
public:
    explicit SettingsPanel(QWidget* parent = nullptr);

    ~SettingsPanel() = default;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void SetupUi();

    QPixmap pixmap_logo_;
};


#endif // SETTINGSPANEL_H
