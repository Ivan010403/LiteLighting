#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include "../Fixture.h"
#include <map>

class AbstractCommand {
public:
    AbstractCommand() = default;
    ~AbstractCommand() = default;

    void AddAction(Fixture* fxtr, ChannelType channel, uint8_t value) {
        actions_[fxtr][channel] = value;
    }

    void Execute() {
        for (auto& action : actions_) {
            for (auto& change : action.second) {
                qDebug() << "Отправка данных по " << (action.first)->GetFixtureId() << ChannelTypeToQString(change.first) << change.second;
                (action.first)->ChangeData(change.first, change.second);
            }
        }
    }

    int Size() const {
        return actions_.size();
    }

protected:
    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;
};

#endif // ABSTRACTCOMMAND_H
