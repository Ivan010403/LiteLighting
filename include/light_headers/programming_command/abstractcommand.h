#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <map>

#include "../Fixture.h"
#include "light_headers/CustomTypeEnum.h"

class AbstractCommand {
public:
    AbstractCommand() = default;
    ~AbstractCommand() = default;

    void AddAction(Fixture* fxtr, ChannelType channel, uint8_t value);

    void Execute();

    int Size() const;

    bool SetProgrammingType(ProgrammingType type_channels_);

    bool CheckExistingChannel(Fixture* fxtr, ChannelType channel);

private:
    void ClearUnusedCommands();

    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;

    ProgrammingType type_channels_;
};

#endif // ABSTRACTCOMMAND_H
