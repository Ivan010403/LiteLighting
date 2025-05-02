#include "light_headers/CustomTypeEnum.h"

QString ChannelTypeToQString(ChannelType type) {
    switch(type) {
    case ChannelType::Dimmer:
        return QStringLiteral("Dimmer");
    case ChannelType::Pan:
        return QStringLiteral("Pan");
    case ChannelType::Tilt:
        return QStringLiteral("Tilt");
    case ChannelType::Gobo:
        return QStringLiteral("Gobo");
    case ChannelType::R:
        return QStringLiteral("R");
    case ChannelType::G:
        return QStringLiteral("G");
    case ChannelType::B:
        return QStringLiteral("B");
    case ChannelType::Beam:
        return QStringLiteral("Beam");
    case ChannelType::Focus:
        return QStringLiteral("Focus");
    case ChannelType::Control:
        return QStringLiteral("Control");
    case ChannelType::Empty:
        return QStringLiteral("Empty");
    default:
        return QStringLiteral("error");
    }
}

std::map<const PropertyType, const std::vector<ChannelType>> map_property_to_channel = {
    {PropertyType::Dimmer, {ChannelType::Dimmer}},
    {PropertyType::Position, {ChannelType::Pan, ChannelType::Tilt}},
    {PropertyType::Gobo, {ChannelType::Gobo}},
    {PropertyType::Color, {ChannelType::R, ChannelType::G, ChannelType::B}},
    {PropertyType::Beam, {ChannelType::Beam}},
    {PropertyType::Focus, {ChannelType::Focus}},
    {PropertyType::Control, {ChannelType::Control}},
};

auto create_combined_vector() {
    std::vector<ChannelType> v1 = map_property_to_channel[PropertyType::Dimmer];
    std::vector<ChannelType> v2 = map_property_to_channel[PropertyType::Gobo];
    std::vector<ChannelType> v3 = map_property_to_channel[PropertyType::Beam];

    std::vector<ChannelType> result;
    result.insert(result.end(), v1.begin(), v1.end());
    result.insert(result.end(), v2.begin(), v2.end());
    result.insert(result.end(), v3.begin(), v3.end());
    return result;
}

std::map<const ProgrammingType, const std::vector<ChannelType>> map_programming_to_channel = {
    {ProgrammingType::Position, map_property_to_channel[PropertyType::Position]},
    {ProgrammingType::Color, map_property_to_channel[PropertyType::Color]},
    {ProgrammingType::Beam, create_combined_vector()},
    {ProgrammingType::Focus, map_property_to_channel[PropertyType::Focus]},
};

std::map<const ProgrammingType, const QString> map_programming_to_qstring = {
    {ProgrammingType::Group, QStringLiteral("Group")},
    {ProgrammingType::Default, QStringLiteral("Default")},
    {ProgrammingType::Position, QStringLiteral("Position")},
    {ProgrammingType::Color, QStringLiteral("Color")},
    {ProgrammingType::Beam, QStringLiteral("Beam")},
    {ProgrammingType::Focus, QStringLiteral("Focus")},
};

