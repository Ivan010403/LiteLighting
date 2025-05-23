#include "light_headers/Fixture.h"

Fixture::Fixture(int group_id) :
    fixture_id_(group_id),
    universe_id_(0),
    dmx_address_(0),
    channel_amount_(0),
    name_(""),
    power_(0),
    channel_types_(nullptr),
    dmx_data_(nullptr),
    raw_data_(nullptr) {}

Fixture::Fixture (int fixture_id, int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                 QString name, int power, const ChannelType* channels, ola::DmxBuffer* dmx_data) :
    fixture_id_ (fixture_id),
    universe_id_(universe_id),
    dmx_address_(dmx_address),
    channel_amount_(channel_amount),
    name_(name),
    power_(power),
    channel_types_(new ChannelType[channel_amount_] {}),
    dmx_data_(dmx_data),
    raw_data_(new uint8_t[channel_amount] {})
{
    for (int i = 0; i < channel_amount_; ++i) {
        channel_types_[i] = channels[i];
        channels_[channels[i]] = &raw_data_[i];
    }
}

Fixture::Fixture (Fixture&& fxtr) :
    fixture_id_ (fxtr.fixture_id_),
    universe_id_(fxtr.universe_id_),
    dmx_address_(fxtr.dmx_address_),
    channel_amount_(fxtr.channel_amount_),
    name_(fxtr.name_),
    power_(fxtr.power_),
    channels_(std::move(fxtr.channels_)),
    dmx_data_(fxtr.dmx_data_),
    raw_data_(fxtr.raw_data_)
{
    qDebug() << "ALARM! MOVE CONSTRUCTOR INTO FIXTURE";
    fxtr.raw_data_ = nullptr;
}

Fixture::~Fixture() {
    if (raw_data_) {
        delete[] raw_data_;
    }

    if (channel_types_) {
        delete[] channel_types_;
    }
}

bool Fixture::operator== (const Fixture& fxtr) const {
    return this->fixture_id_ == fxtr.fixture_id_;
}

int Fixture::GetFixtureId() const {
    return fixture_id_;
}

bool Fixture::isHaveChannel(ChannelType type) const {
    return channels_.count(type) > 0 ? true : false;
}


void Fixture::ChangeData(ChannelType channel_type, int value) {
    *channels_[channel_type] = value; // что если value больше 255?
    SendDmxData();
}

void Fixture::AddFixture(Fixture*) {}

void Fixture::DeleteFixture(Fixture*) {}

void Fixture::SetDmxBuffer(ola::DmxBuffer* dmx_data) {
    dmx_data_ = dmx_data;
}

QJsonObject Fixture::SaveDataToShow() {
    QJsonObject json;
    json["fix_id"] = fixture_id_;
    json["univ_id"] =  universe_id_;
    json["dmx_addr"] = dmx_address_;
    json["chan_amount"] = channel_amount_;
    json["name"] = name_;
    json["power"] = power_;
    json["group_id"] = group_id_;
    json["group_name"] = group_name_;


    QJsonArray channels_array;
    QJsonArray channels_value;
    for (int i = 0; i < channel_amount_; ++i) {
        channels_array.append(static_cast<int>(channel_types_[i]));
        channels_value.append(*channels_[channel_types_[i]]);
    }
    json["channels_type"] = channels_array;
    json["channels_value"] = channels_value;

    return json;
}

void Fixture::SendDmxData() {
    dmx_data_->SetRange(dmx_address_, raw_data_, channel_amount_);
}
