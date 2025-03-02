#ifndef FIXTUREARRAY_H
#define FIXTUREARRAY_H
#include "light_headers/Fixture.h"
#include "light_headers/DmxGateway.h"

class FixtureArray {
public:
    explicit FixtureArray(DmxGateway& dmx_gtw) : dmx_gateway_(dmx_gtw) {}

    ~FixtureArray() {
        for (int i = 0; i < size_; ++i) {
            delete vector_fixture_[i];
        }
    }

    Fixture* getFixtureByIndex(int index);

    void createNewFixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                          std::string name, const ChannelType* channels);

    int size() const;

    FixtureArray() = delete;
    FixtureArray(const FixtureArray& dmx_gtw) = delete;
    FixtureArray(FixtureArray&& dmx_gtw) = delete;
    FixtureArray& operator= (const FixtureArray& dmx_gtw) = delete;
    FixtureArray& operator= (FixtureArray&& dmx_gtw) = delete;

private:
    std::vector <Fixture*> vector_fixture_;
    int size_ = 0; // maybe unsigned?
    DmxGateway& dmx_gateway_; // что если объект разрушится? ссылка будет указывать на дичь
};

#endif // FIXTUREARRAY_H
