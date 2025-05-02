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
