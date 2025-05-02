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

protected:
    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;
};

#endif // ABSTRACTCOMMAND_H
