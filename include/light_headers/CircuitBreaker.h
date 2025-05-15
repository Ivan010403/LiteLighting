#ifndef CIRCUITBREAKER_H
#define CIRCUITBREAKER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>

#include "light_headers/FixtureArray.h"

// class CircuitBreaker : public QObject {
//     Q_OBJECT
// public:
//     static CircuitBreaker& instance() { static CircuitBreaker m; return m; }

//     void SaveDataToShow(QJsonObject& root);

//     void LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array);
// private:
//     // Mediator() = default;

//     int amperage_;
//     int breakers_number_;
// };

#endif // CIRCUITBREAKER_H
