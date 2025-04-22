#ifndef CHANNELTYPEENUM_H
#define CHANNELTYPEENUM_H

enum class ChannelType: uint8_t {
    Dimmer,
    R,
    G,
    B,
    Pan,
    Tilt
}; // добавить

enum class ProgrammingType: uint8_t {
    Group,
    Default,
    Position,
    Color,
    Beam,
    Focus,
};

#endif // CHANNELTYPEENUM_H
