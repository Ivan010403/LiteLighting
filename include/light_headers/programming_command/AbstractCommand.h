#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include "../Fixture.h"
#include "light_headers/CustomTypeEnum.h"

class AbstractCommand {
    friend class CommandArray;
public:
    AbstractCommand() = default;

    ~AbstractCommand() = default;

    void AddAction(Fixture* fxtr, ChannelType channel, uint8_t value);

    void Execute();

    int Size() const;

    bool SetProgrammingType(ProgrammingType type_channels_, int number);

    bool CheckExistingChannel(Fixture* fxtr, ChannelType channel);

private:
    void ClearUnusedCommands();

    QJsonObject SaveDataToShow();

    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;

    ProgrammingType type_channels_;
    int number_;
};

#endif // ABSTRACTCOMMAND_H
