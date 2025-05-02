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

std::unordered_map<PropertyType, std::vector<ChannelType>> map_property_to_channel = { // добавить константность
    {PropertyType::Dimmer, {ChannelType::Dimmer}},
    {PropertyType::Position, {ChannelType::Pan, ChannelType::Tilt}},
    {PropertyType::Gobo, {ChannelType::Gobo}},
    {PropertyType::Color, {ChannelType::R, ChannelType::G, ChannelType::B}},
    {PropertyType::Beam, {ChannelType::Beam}},
    {PropertyType::Focus, {ChannelType::Focus}},
    {PropertyType::Control, {ChannelType::Control}},
};

std::unordered_map<ProgrammingType, QString> map_programming_to_qstring = {
    {ProgrammingType::Group, QStringLiteral("Group")},
    {ProgrammingType::Default, QStringLiteral("Default")},
    {ProgrammingType::Position, QStringLiteral("Position")},
    {ProgrammingType::Color, QStringLiteral("Color")},
    {ProgrammingType::Beam, QStringLiteral("Beam")},
    {ProgrammingType::Focus, QStringLiteral("Focus")},
};

