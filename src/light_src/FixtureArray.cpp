#include "light_headers/FixtureArray.h"

void FixtureArray::createNewFixture (unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount, std::string name, std::unordered_map <ChannelType, unsigned char>& channels) {
    ++size_;
    vector_fixture_.push_back(Fixture(universe_id, dmx_address, channel_amount, name, channels));
}

int FixtureArray::size() const {
    return size_;
}
