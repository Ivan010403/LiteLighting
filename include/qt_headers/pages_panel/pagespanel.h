#ifndef PAGESPANEL_H
#define PAGESPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "./pages_button/pagesbutton.h"

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
    PagesButton* btn_programming_;
    PagesButton* btn_busking_;
    PagesButton* btn_patching_;
    PagesButton* btn_settings_;
};

#endif // PAGESPANEL_H
