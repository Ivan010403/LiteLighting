#ifndef CUSTOMTYPEENUM_H
#define CUSTOMTYPEENUM_H

#include <QString>
#include <unordered_map>
#include <vector>

enum class ChannelType: uint8_t {
    Dimmer,
    R,
    G,
    B,
    Pan,
    Tilt,
    Gobo,
    Beam,
    Focus,
    Control,
    Empty // сделать лучше!!
}; // добавить

enum class PropertyType: uint8_t {
    Dimmer,
    Position,
    Gobo,
    Color,
    Beam,
    Focus,
    Control
};

enum class ProgrammingType: uint8_t {
    Group,
    Default,
    Position,
    Color,
    Beam,
    Focus
    // Cue
};

QString ChannelTypeToQString(ChannelType type);

extern std::unordered_map<ProgrammingType, QString> map_programming_to_qstring;

extern std::unordered_map<PropertyType, std::vector<ChannelType>> map_property_to_channel;

#endif // CUSTOMTYPEENUM_H
