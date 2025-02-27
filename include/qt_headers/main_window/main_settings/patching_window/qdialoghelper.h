#ifndef QDIALOGHELPER_H
#define QDIALOGHELPER_H
#include <QDialog>

#include "light_headers/Patcher.h"

class QDialogHelper : public QDialog {
    Q_OBJECT

public:
    explicit QDialogHelper(Patcher* dmx_patcher, QWidget* parent = nullptr) : dmx_patcher_(dmx_patcher), QDialog(parent) {
        SetupUi();
        SetupConnections();
    }

    ~QDialogHelper() {}

private:
    void SetupUi() {
        this->setWindowTitle("Создание новой Fixture");
        this->resize(1280,720);
        this->setMinimumSize(1280,720);
    }

    void SetupConnections() {

    }

    Patcher* dmx_patcher_;
};

#endif // QDIALOGHELPER_H
