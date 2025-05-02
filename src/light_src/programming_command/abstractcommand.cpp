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

bool AbstractCommand::SetProgrammingType(ProgrammingType type_channels) {
    type_channels_ = type_channels;

    ClearUnusedCommands();

    return actions_.size() != 0 ? true : false;
}

void AbstractCommand::ClearUnusedCommands() {
    const auto& vec = map_programming_to_channel[type_channels_];

    auto main_it = actions_.begin();

    while (main_it != actions_.end()) {
        auto& inner_map = main_it->second;
        auto it = inner_map.begin();

        while (it != inner_map.end()) {
            if (std::find(vec.begin(), vec.end(), it->first) == vec.end()) {
                qDebug() << "Удаляю " << ChannelTypeToQString(it->first);
                it = inner_map.erase(it); // erase() возвращает следующий итератор
            } else {
                ++it;
            }
        }

        if (inner_map.size() == 0) main_it = actions_.erase(main_it);
        else ++main_it;
    }
}

bool AbstractCommand::CheckExistingChannel(Fixture* fxtr, ChannelType channel) {
    if ((actions_.count(fxtr) > 0) && (actions_[fxtr].count(channel) > 0)) return true;
    return false;
}
