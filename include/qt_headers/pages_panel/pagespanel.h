#ifndef PAGESPANEL_H
#define PAGESPANEL_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class PagesPanel : public QWidget {
    Q_OBJECT
public:
    explicit PagesPanel(QWidget* parent = nullptr);

    ~PagesPanel() = default;

signals:
    void showProgramming();
    void showBusking();
    void showPatchSheet();
    void showSettings();

private:
    void SetupUi();

    void SetupConnections();

    QVBoxLayout* vlayout_main_;
    QPushButton* btn_programming_;
    QPushButton* btn_busking_;
    QPushButton* btn_patching_;
    QPushButton* btn_settings_;
};

#endif // PAGESPANEL_H
