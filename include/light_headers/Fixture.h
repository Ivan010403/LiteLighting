#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_
#include <unordered_map>
#include <string>
#include <stdint.h> // проверить мало ли уже где-то заинклудили


enum class ChannelType: unsigned char {
    Dimmer,
    R,
    G,
    B,
    Pan
};

class Fixture {
public:
    Fixture() = delete;

    Fixture (unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount, std::string name) :
        universe_id_(universe_id),
        name_(name)
    {
        for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
            // channels_[ChannelType::Dimmer] =
        }
    } // TODO: implement me!
        
protected:
    unsigned int universe_id_;
    std::string name_;
    std::unordered_map <ChannelType, unsigned char> channels_;

private:
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
