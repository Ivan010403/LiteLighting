#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include "light_headers/FixtureArray.h"
#include "light_headers/programming_command/CommandArray.h"

class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    explicit SettingsWindow(FixtureArrayModel* dmx_fixture_array, QWidget* parent = nullptr) :
        dmx_fixture_array_(dmx_fixture_array),
        QWidget(parent)
    {
        SetupUi();
        SetupConnections();
    }

    ~SettingsWindow() = default;

private slots:
    void onLoadClicked() {
        QFile file("test3.json");
        if (!file.open(QIODevice::ReadOnly)) return; // обработать нормально

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject root = doc.object();


        dmx_fixture_array_->LoadDataFromShow(root);

        CommandArray::instance().LoadDataFromShow(root, dmx_fixture_array_);
    }

    void onSaveClicked() {
        QJsonObject root;

        dmx_fixture_array_->SaveDataToShow(root);

        CommandArray::instance().SaveDataToShow(root);


        QFile file("test3.json");
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Ошибка открытия файла для записи";
        }

        QJsonDocument doc(root);
        file.write(doc.toJson());
        file.close();
    }

private:
    void SetupUi() {
        hlayout_main_ = new QHBoxLayout(this);

        btn_load_showfile_ = new QPushButton("Load show", this);
        btn_save_showfile_ = new QPushButton("Save show", this);

        hlayout_main_->addWidget(btn_load_showfile_);
        hlayout_main_->addWidget(btn_save_showfile_);
    }

    void SetupConnections() {
        connect(btn_load_showfile_, &QPushButton::clicked, this, &SettingsWindow::onLoadClicked);
        connect(btn_save_showfile_, &QPushButton::clicked, this, &SettingsWindow::onSaveClicked);

    }

    FixtureArrayModel* dmx_fixture_array_;

    QHBoxLayout* hlayout_main_;
    QPushButton* btn_load_showfile_;
    QPushButton* btn_save_showfile_;
};

#endif // SETTINGSWINDOW_H
