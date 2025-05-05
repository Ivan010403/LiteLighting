#include "light_headers/programming_command/CommandArray.h"

void CommandArray::AddCommand(AbstractCommand* command) {
    map_commands_[command->type_channels_][command->number_] = command;
}

void CommandArray::DeleteCommand(ProgrammingType type_channels_, int number) {
    if (map_commands_.count(type_channels_) > 0) map_commands_[type_channels_].erase(number);

    if (map_commands_[type_channels_].size() == 0) map_commands_.erase(type_channels_);
}

void CommandArray::SaveDataToShow(QJsonObject& root) {
    QJsonArray json_array;

    for (const auto& var : map_commands_) {
        for (const auto& val : var.second) {
            json_array.append(val.second->SaveDataToShow());
        }
    }

    root["commands"] = json_array;
}

void CommandArray::Clear() {
    for (auto& var : map_commands_) {
        for (const auto& val : var.second) {
            delete val.second;
            emit DeletingCommands(var.first, val.first);
        }
        var.second.clear();
    }
    map_commands_.clear();
}

void CommandArray::LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array) {
    Clear();

    QJsonArray commands_array = root["commands"].toArray();

    for (const QJsonValue& val : commands_array) {
        QJsonObject command = val.toObject();

        QString name = command["name"].toString();
        ProgrammingType type = static_cast<ProgrammingType>(command["progr_type"].toInt());
        int number = command["number"].toInt();


        AbstractCommand* abstract_command = new AbstractCommand();
        abstract_command->SetData(type, number, name);


        QJsonArray fixtures = command["command"].toArray();

        for (const QJsonValue& fxtr : fixtures) {
            QJsonObject fixture = fxtr.toObject();

            int fix_id = fixture["fix_id"].toInt();

            Fixture* curr_fxtr = dmx_fixture_array->GetFixtureByFixtureId(fix_id); // что если нет такой фикстуры?

            QJsonArray actions = fixture["actions"].toArray();

            for (const QJsonValue& act : actions) {
                QJsonObject action = act.toObject();

                ChannelType ch_type = static_cast<ChannelType>(action["channel"].toInt());
                int value = action["value"].toInt();

                abstract_command->AddAction(curr_fxtr, ch_type, value);
            }
        }
        emit AddingCommand(type, number, abstract_command);
        AddCommand(abstract_command);
    }
}
