#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_
#include <unordered_map>
#include <string>
#include <stdint.h> // проверить мало ли уже где-то заинклудили
#include <ola/DmxBuffer.h>
#include <light_headers/CustomTypeEnum.h>

#include <iostream>

class Fixture {
public:
    //--------------------constructors and destructor--------------------------------
    explicit Fixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
            std::string name, const ChannelType* channels, ola::DmxBuffer& dmx_data) :
        fixture_id_ (fixture_id),
        universe_id_(universe_id),
        dmx_address_(dmx_address),
        channel_amount_(channel_amount),
        name_(name),
        dmx_data_(dmx_data),
        raw_data_(new uint8_t[channel_amount] {})
    {
        for (int i = 0; i < channel_amount_; ++i) {
            channels_[channels[i]] = &raw_data_[i];
        }
    }

    explicit Fixture (Fixture&& fxtr) : // ЗДЕСЬ НЕТ FIXTURE ID!
        fixture_id_ (fxtr.fixture_id_),
        universe_id_(fxtr.universe_id_),
        dmx_address_(fxtr.dmx_address_),
        channel_amount_(fxtr.channel_amount_),
        name_(fxtr.name_),
        channels_(std::move(fxtr.channels_)),
        dmx_data_(fxtr.dmx_data_),
        raw_data_(fxtr.raw_data_)
    {
        fxtr.raw_data_ = nullptr;
    }

    ~Fixture() {
        if (raw_data_) {
            delete[] raw_data_;
        }
    }
    //-------------------------------------------------------------------------------

    //---------------------------local functions-------------------------------------
    // refactor!!!
    unsigned int GetFixtureId() const { // maybe const?
        return fixture_id_;
    }

    void ChangeData(ChannelType channel_type, int value) {
        *channels_[channel_type] = value;
        SendDmxData();
    }
    // refactor!!!
    //-------------------------------------------------------------------------------

    //---------------------------deleted functions-----------------------------------
    Fixture() = delete;
    Fixture (const Fixture& fxtr) = delete;
    Fixture& operator= (const Fixture& fxtr) = delete;
    Fixture& operator= (Fixture&& fxtr) = delete;
    //-------------------------------------------------------------------------------

public: // ПРИДУМАТЬ ЧТО-ТО С ЭТИМ. МОЖЕТ БЫТЬ FRIEND CLASS?
    void SendDmxData() {
        dmx_data_.SetRange(dmx_address_, raw_data_, channel_amount_);
    }

    unsigned int fixture_id_;
    unsigned int universe_id_;
    unsigned int group_id_ = 0; // проинициализировать!!!!!!!!!!!!!!!!!!!!!!!
    uint16_t dmx_address_; // пока пусть будет константой?
    uint16_t channel_amount_;
    std::string name_;
    std::unordered_map <ChannelType, uint8_t*> channels_; // может константный указатель?

    ola::DmxBuffer& dmx_data_;
    uint8_t* raw_data_; // maybe smart pointers?
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
