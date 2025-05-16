#include "light_headers/CircuitBreaker.h"

void CircuitBreaker::SaveDataToShow(QJsonObject& root){

}

void CircuitBreaker::LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array){

}

void CircuitBreaker::AddBreaker(int index, int phase_number, int amperage) {
    if (index >= breakers_.size()) breakers_.push_back(std::pair<int, int> (phase_number, amperage));
    else { breakers_[index].first = phase_number; breakers_[index].second = amperage; }
}

void CircuitBreaker::SetAmperage(int value) {
    amperage_ = value;
}

int CircuitBreaker::size() const {
    return breakers_number_;
}

int CircuitBreaker::getPhase(int index) const {
    return breakers_[index].first;
}

int CircuitBreaker::getBreakerAmperage(int index) const {
    return breakers_[index].second;
}

bool CircuitBreaker::isExisting(int index) const {
    return index < breakers_.size();
}

CircuitBreaker& CircuitBreaker::operator++() {
    ++breakers_number_;
    return *this;
}

