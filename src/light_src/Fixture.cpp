#include "light_headers/Fixture.h"

Fixture::Fixture(unsigned int group_id, std::string name) :
    name_(name),
    group_id_(group_id),
    fixture_id_(0),
    universe_id_(0),
    dmx_address_(0),
    channel_amount_(0),
    dmx_data_(nullptr),
    raw_data_(nullptr) {}

Fixture::Fixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                 std::string name, const ChannelType* channels, ola::DmxBuffer* dmx_data) :
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

Fixture::Fixture (Fixture&& fxtr) :
    fixture_id_ (fxtr.fixture_id_),
    universe_id_(fxtr.universe_id_),
    dmx_address_(fxtr.dmx_address_),
    channel_amount_(fxtr.channel_amount_),
    name_(fxtr.name_),
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
}

unsigned int Fixture::GetFixtureId() const {
    return fixture_id_;
}

void Fixture::ChangeData(ChannelType channel_type, int value) {
    *channels_[channel_type] = value;
    SendDmxData();
}

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

bool Fixture::SaveDataToShow() const {
    QJsonObject json;
    json["fix_id"] = static_cast<int>(fixture_id_); // неприятно!
    json["univ_id"] =  static_cast<int>(universe_id_);
    json["dmx_addr"] = dmx_address_;
    json["chan_amount"] = channel_amount_;
    json["name"] = QString::fromStdString(name_); // сделать так чтобы name был QString!

    QJsonArray channels_array;
    for (const auto& tag : channels_) {
        channels_array.append(static_cast<int>(tag.first));
    }
    json["channels_type"] = channels_array;

    QJsonArray channels_value;
    for (const auto& tag : channels_) {
        channels_value.append(*tag.second);
    }
    json["channels_value"] = channels_value;


    QFile file("test.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Ошибка открытия файла для записи";
        return false;
    }

    QJsonDocument doc(json);
    file.write(doc.toJson());
    file.close();

    return true;
}

void Fixture::SendDmxData() {
    dmx_data_->SetRange(dmx_address_, raw_data_, channel_amount_);
}
