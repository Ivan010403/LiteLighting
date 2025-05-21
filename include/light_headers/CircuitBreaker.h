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

    void AddBreaker(int, int, int);
    void SetAmperage(int);

    int size() const;
    int getPhase(int) const;
    int getBreakerAmperage(int) const;

    bool isExisting(int) const;

    CircuitBreaker& operator++();

    int amperage_;

    std::vector<std::pair<bool, int>> data_of_breakers;

    std::vector<int> phase_powers_ = std::vector<int> (3, 0);

    int total_power_ = 0;

signals:
    void UploadingData();

private:
    CircuitBreaker() = default;

    int breakers_number_;

    std::vector<std::pair<int, int>> breakers_;
};

#endif // CIRCUITBREAKER_H
