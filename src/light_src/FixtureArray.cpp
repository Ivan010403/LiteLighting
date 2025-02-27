#include "light_headers/FixtureArray.h"

// refactor!!!
Fixture* FixtureArray::getFixtureByIndex(int index) {
    return vector_fixture_[index];
}

void FixtureArray::createNewFixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                                    std::string name, const ChannelType *channels) {
    ++size_;
    vector_fixture_.push_back(new Fixture(fixture_id, universe_id, dmx_address, channel_amount, name,
                                    channels, dmx_gateway_.GetBuffer(universe_id)));
}

int FixtureArray::size() const {
    return size_;
}
