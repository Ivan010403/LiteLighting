#ifndef CIRCUITBREAKER_H
#define CIRCUITBREAKER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>

#include "light_headers/FixtureArray.h"

class CircuitBreaker : public QObject {
    Q_OBJECT
public:
    static CircuitBreaker& instance() { static CircuitBreaker m; return m; }

    void SaveDataToShow(QJsonObject& root);

    void LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array);

    void AddBreaker(int, int, int);
    void SetAmperage(int);

    int size() const;
    int getPhase(int) const;
    int getBreakerAmperage(int) const;

    bool isExisting(int) const;

    CircuitBreaker& operator++();

signals:
    void UploadingData();

private:
    CircuitBreaker() = default;

    int amperage_;
    int breakers_number_;

    std::vector<std::pair<int, int>> breakers_;
};

#endif // CIRCUITBREAKER_H
