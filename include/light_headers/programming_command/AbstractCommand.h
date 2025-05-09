#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QObject>

#include "../Mediator.h"
#include "light_headers/CustomTypeEnum.h"

class AbstractCommand : public QObject {
Q_OBJECT
    friend class CommandArray;
public:
    AbstractCommand();

    ~AbstractCommand() = default;

    void AddAction(Fixture* fxtr, ChannelType channel, uint8_t value);

    void Execute();

    int Size() const;

    bool SetData(ProgrammingType type_channels_, int number, QString name);

    bool CheckExistingChannel(Fixture* fxtr, ChannelType channel);

    bool CheckExistingProperty(Fixture* fxtr, PropertyType prop_type);

    QString name_;

private slots:
    void onDeletedFixture(Fixture* fxtr);

private:
    void ClearUnusedCommands();

    QJsonObject SaveDataToShow();

    std::map<Fixture*, std::map<ChannelType, uint8_t>> actions_;

    ProgrammingType type_channels_;
    int number_;
};

#endif // ABSTRACTCOMMAND_H
