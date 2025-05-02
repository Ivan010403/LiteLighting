#include "light_headers/programming_command/abstractcommand.h"


void AbstractCommand::AddAction(Fixture* fxtr, ChannelType channel, uint8_t value) {
    actions_[fxtr][channel] = value;
}

void AbstractCommand::Execute() {
    for (auto& action : actions_) {
        for (auto& change : action.second) {
            qDebug() << "Отправка данных по " << (action.first)->GetFixtureId() << ChannelTypeToQString(change.first) << change.second;
            (action.first)->ChangeData(change.first, change.second);
        }
    }
}

int AbstractCommand::Size() const {
    return actions_.size();
}

void AbstractCommand::SetProgrammingType(ProgrammingType type_channels) {
    type_channels_ = type_channels;

    ClearUnusedCommands();
}

void AbstractCommand::ClearUnusedCommands() {
    // for (auto& action : actions_) {
    //     for (auto& change : action.second) {
    //         if (change.first == )
    //         (action.first)->ChangeData(change.first, change.second);
    //     }
    // }
}

// std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;
