#ifndef OPENLIGHTING_INCLUDE_FIXTURE_H_
#define OPENLIGHTING_INCLUDE_FIXTURE_H_

#include <ola/DmxBuffer.h>

#include <string>
#include <stdint.h> // проверить мало ли уже где-то заинклудили

#include <QWidget> // для qdebug
#include <QJsonObject>
#include <QJsonArray>

#include <light_headers/CustomTypeEnum.h>

class Fixture {
    friend class FixtureArrayModel;
public:
    //--------------------constructors and destructor--------------------------------
    explicit Fixture(int group_id, std::string name);

    explicit Fixture (int fixture_id, int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                     std::string name, const ChannelType* channels, ola::DmxBuffer* dmx_data);

    explicit Fixture (Fixture&& fxtr);

    virtual ~Fixture();

    bool operator== (const Fixture& fxtr) const;
    //-------------------------------------------------------------------------------

    //---------------------------local functions-------------------------------------
    int GetFixtureId() const;

    virtual void ChangeData(ChannelType channel_type, int value);
    virtual void AddFixture(Fixture*);

    QJsonObject SaveDataToShow();
    //-------------------------------------------------------------------------------

    //---------------------------deleted functions-----------------------------------
    Fixture (const Fixture& fxtr) = delete;
    Fixture& operator= (const Fixture& fxtr) = delete;
    Fixture& operator= (Fixture&& fxtr) = delete;
    //-------------------------------------------------------------------------------

public: // надо заменить как-то
    void SendDmxData();
    std::unordered_map <ChannelType, uint8_t*> channels_; // может заменить на map?
    int group_id_ = 0;

private:

    int fixture_id_;
    int universe_id_;
    uint16_t dmx_address_; // пока пусть будет константой?
    uint16_t channel_amount_;

    std::string name_;
    ChannelType* channel_types_;

    ola::DmxBuffer* dmx_data_;
    uint8_t* raw_data_;
};



#endif  // OPENLIGHTING_INCLUDE_FIXTURE_H_
