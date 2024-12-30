#ifndef FIXTUREARRAY_H
#define FIXTUREARRAY_H
#include <vector> // проверить нет ли вхождения уже этого файла
#include "light_headers/Fixture.h"

class FixtureArray {
public:
    FixtureArray() = default;

    void createNewFixture (unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount, std::string name, std::unordered_map <ChannelType, unsigned char>& channels) {
        ++size_;
        vector_fixture_.push_back(Fixture(universe_id, dmx_address, channel_amount, name, channels));
    }

    int size() const {
        return size_;
    }
protected:

private:
    int size_ = 0; // maybe unsigned?
    std::vector <Fixture> vector_fixture_;
};

#endif // FIXTUREARRAY_H
