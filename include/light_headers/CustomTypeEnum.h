#ifndef CUSTOMTYPEENUM_H
#define CUSTOMTYPEENUM_H

#include <QString>
#include <map>
#include <vector>

// разобраться с constexpr inline и прочим

enum class ChannelType: uint8_t {
    Dimmer,
    R,
    G,
    B,
    A,
    Pan,
    Tilt,
    Gobo,
    Beam,
    Focus,
    Control,
    Flex
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
    Cue,
    Position,
    Color,
    Beam,
    Focus
};

QString ChannelTypeToQString(ChannelType type);

QString PropertyTypeToQString(PropertyType type);

QString ProgrammingTypeToQString(ProgrammingType type);

extern std::map<const PropertyType, const std::vector<ChannelType>> map_property_to_channel;

extern std::map<const ProgrammingType, const std::vector<ChannelType>> map_programming_to_channel;

#endif // CUSTOMTYPEENUM_H
