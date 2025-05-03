#ifndef UPLOADER_H
#define UPLOADER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

#include "FixtureGroup.h"

class Uploader {
public:
    static Uploader& instance() { static Uploader m; return m; }

    void LoadShowData(Fixture* fxtr) {

    }

    void SaveShowData(Fixture* fxtr) {
        // Создаём JSON-объект

    }
private:
    Uploader() = default;
};

#endif // UPLOADER_H
