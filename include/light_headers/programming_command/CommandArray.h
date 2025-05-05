#ifndef COMMANDARRAY_H
#define COMMANDARRAY_H

#include <QFile>
#include <QJsonDocument>

#include "AbstractCommand.h"
#include "light_headers/FixtureArray.h"

class CommandArray : public QObject {
    Q_OBJECT
public:
    static CommandArray& instance() { static CommandArray com_array_; return com_array_; }

    void AddCommand(AbstractCommand* command);

    void DeleteCommand(ProgrammingType type_channels_, int number);

    void SaveDataToShow(QJsonObject& root);

    void LoadDataFromShow(QJsonObject& root, FixtureArrayModel* dmx_fixture_array);

signals:
    void AddingCommand(ProgrammingType, int, AbstractCommand*);
    void DeletingCommands(ProgrammingType, int);

private:
    void Clear();

    CommandArray() = default;

    std::map <ProgrammingType, std::map<int, AbstractCommand*>> map_commands_;
};

#endif // COMMANDARRAY_H
