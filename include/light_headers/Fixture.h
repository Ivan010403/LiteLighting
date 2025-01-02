#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_
#include <unordered_map>
#include <vector>
#include <string>
#include <stdint.h> // проверить мало ли уже где-то заинклудили
#include <ola/DmxBuffer.h>


enum class ChannelType: uint8_t {
    Dimmer,
    R,
    G,
    B,
    Pan,
    Tilt,
    Last
};

class Fixture {
public:
    Fixture() = delete;

    Fixture (unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount, std::string name, std::vector<ChannelType>& channels, ola::DmxBuffer& buff) :
        universe_id_(universe_id),
        dmx_address_(dmx_address),
        channel_amount_(channel_amount),
        name_(name),
        dmx_data_(buff),
        raw_data_(new uint8_t[channel_amount] {})
    {
        for (int i = 0; i < channel_amount_; ++i) {
            channels_[channels[i]] = &raw_data_[i];
        }
    }

    ~Fixture() {
        delete[] raw_data_;
    }
        
protected:
    unsigned int universe_id_;
    uint16_t dmx_address_; // пока пусть будет константой
    uint16_t channel_amount_;
    std::string name_;
    std::unordered_map <ChannelType, uint8_t*> channels_;

    uint8_t* raw_data_; // maybe smart pointers?
    ola::DmxBuffer& dmx_data_;

private:
    void SendDmxData() {
        dmx_data_.SetRange(dmx_address_, raw_data_ ,channel_amount_);
    }
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
