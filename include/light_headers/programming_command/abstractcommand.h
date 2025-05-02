#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include "../Fixture.h"
#include <map>

class AbstractCommand {
public:
    AbstractCommand() = default;
    ~AbstractCommand() = default;

    void AddAction(Fixture* fxtr, ChannelType channel, uint8_t value);

    void Execute();

    int Size() const;

    void SetProgrammingType(ProgrammingType type_channels_);

    void ClearUnusedCommands();

protected:
    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;

    ProgrammingType type_channels_;
};

#endif // ABSTRACTCOMMAND_H
