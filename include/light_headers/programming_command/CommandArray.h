#ifndef COMMANDARRAY_H
#define COMMANDARRAY_H

#include <QFile>
#include <QJsonDocument>

#include "abstractcommand.h"

class CommandArray : public QObject {
    Q_OBJECT
public:
    static CommandArray& instance() { static CommandArray com_array_; return com_array_; }

    void AddCommand(AbstractCommand* command) {
        map_commands_[command->type_channels_][command->number_] = command;
    }

    void DeleteCommand(ProgrammingType type_channels_, int number) {
        if (map_commands_.count(type_channels_) > 0) map_commands_[type_channels_].erase(number);

        if (map_commands_[type_channels_].size() == 0) map_commands_.erase(type_channels_);
    }

    void SaveDataToShow(QJsonObject& root) {
        QJsonArray json_array;

        for (const auto& var : map_commands_) {
            for (const auto& val : var.second) {
                json_array.append(val.second->SaveDataToShow());
            }
        }

        root["commands"] = json_array;
    }

signals:
    void CommandAdded(ProgrammingType, int);

private:
    CommandArray() = default;

    std::map <ProgrammingType, std::map<int, AbstractCommand*>> map_commands_;
};

#endif // COMMANDARRAY_H
