#ifndef FIXTUREARRAY_H
#define FIXTUREARRAY_H
#include "light_headers/Fixture.h"
#include "light_headers/DmxGateway.h"

class FixtureArray {
public:
    FixtureArray(DmxGateway& dmx_gtw) : dmx_gateway_(dmx_gtw) {}

    void createNewFixture (unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount, std::string name, std::vector<ChannelType>& channels);

    int size() const;
protected:

private:
    int size_ = 0; // maybe unsigned?
    std::vector <Fixture> vector_fixture_;
    DmxGateway& dmx_gateway_; // что если объект разрушится? ссылка будет указывать на дичь
};

#endif // FIXTUREARRAY_H
