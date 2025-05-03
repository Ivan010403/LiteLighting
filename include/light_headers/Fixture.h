#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_

#include <string>
#include <stdint.h> // проверить мало ли уже где-то заинклудили

#include <ola/DmxBuffer.h>

#include <QWidget> // для qdebug

#include <light_headers/CustomTypeEnum.h>
#include "./Mediator.h"

class Fixture {
    friend class FixtureArrayModel;
public:
    //--------------------constructors and destructor--------------------------------
    explicit Fixture(unsigned int group_id, std::string name);

    explicit Fixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                     std::string name, const ChannelType* channels, ola::DmxBuffer* dmx_data);

    explicit Fixture (Fixture&& fxtr);

    virtual ~Fixture();
    //-------------------------------------------------------------------------------

    //---------------------------local functions-------------------------------------
    unsigned int GetFixtureId() const;

    virtual void ChangeData(ChannelType channel_type, int value);

    virtual bool SaveDataToShow() const;
    //-------------------------------------------------------------------------------

    //---------------------------deleted functions-----------------------------------
    Fixture (const Fixture& fxtr) = delete;
    Fixture& operator= (const Fixture& fxtr) = delete;
    Fixture& operator= (Fixture&& fxtr) = delete;
    //-------------------------------------------------------------------------------

public:
    void SendDmxData();

    unsigned int group_id_ = 0;
    std::string name_;
    std::unordered_map <ChannelType, uint8_t*> channels_; // может константный указатель?

private:
    unsigned int fixture_id_;
    unsigned int universe_id_;
    uint16_t dmx_address_; // пока пусть будет константой?
    uint16_t channel_amount_;

    ola::DmxBuffer* dmx_data_;
    uint8_t* raw_data_;
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
