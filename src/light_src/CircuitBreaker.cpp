#include "light_headers/CircuitBreaker.h"

void CircuitBreaker::SaveDataToShow(QJsonObject& root){

}

void CircuitBreaker::LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array){

}

void CircuitBreaker::AddBreaker(int phase_number) {
    breakers_phases_.push_back(phase_number);
}

void CircuitBreaker::SetAmperage(int value) {
    amperage_ = value;
}

int CircuitBreaker::size() const {
    return breakers_number_;
}

CircuitBreaker& CircuitBreaker::operator++() {
    ++breakers_number_;
    return *this;
}

