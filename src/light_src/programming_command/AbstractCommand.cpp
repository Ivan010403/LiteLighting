#include "light_headers/programming_command/AbstractCommand.h"

AbstractCommand::AbstractCommand() {
    connect(&Mediator::instance(), &Mediator::DeletingFixture, this, &AbstractCommand::onDeletedFixture);
}

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

bool AbstractCommand::SetData(ProgrammingType type_channels, int number, QString name) {
    number_ = number;
    type_channels_ = type_channels;
    name_ = name;

    ClearUnusedCommands();

    return actions_.size() != 0 ? true : false; // точно ли произойдет это? проверить, если вообще не проходит комманда под этот тип
}

bool AbstractCommand::CheckExistingChannel(Fixture* fxtr, ChannelType channel) {
    if ((actions_.count(fxtr) > 0) && (actions_[fxtr].count(channel) > 0)) return true;
    return false;
} // нужна для перерисовки контента баттонов в control panel

void AbstractCommand::onDeletedFixture(Fixture* fxtr) {
    for (const auto& var : actions_) {
        if (*var.first == *fxtr) {
            actions_.erase(var.first);
            qDebug() << "AbstractCommand::onDeletedFixture --> удалил фикстуру из команды " << ProgrammingTypeToQString(type_channels_) << number_;
            break;
        }
    }
}

void AbstractCommand::ClearUnusedCommands() { // вроде норм, но протестить
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

QJsonObject AbstractCommand::SaveDataToShow() { // подумать над неймингом и добавить имя самой команды!!!
    QJsonObject json;
    json["name"] = name_;
    json["progr_type"] = static_cast<int>(type_channels_);
    json["number"] =  number_;

    QJsonArray actions;

    for (const auto& var : actions_) {
        QJsonObject act;
        act["fix_id"] = (var.first)->GetFixtureId();

        QJsonArray com;

        for (const auto& val : var.second) {
            QJsonObject temp;
            temp["channel"] = static_cast<int>(val.first);
            temp["value"] = static_cast<int>(val.second);
            com.append(temp);
        }
        act["actions"] = com;

        actions.append(act);
    }

    json["command"] = actions;

    return json;
}
