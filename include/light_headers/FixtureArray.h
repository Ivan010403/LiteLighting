#ifndef FIXTUREARRAY_H
#define FIXTUREARRAY_H

#include <QAbstractTableModel>
#include <QVector>
#include <QFile>
#include <QJsonDocument>

#include "light_headers/Fixture.h"
#include "light_headers/DmxGateway.h"
#include "light_headers/Mediator.h"

class FixtureArrayModel : public QAbstractTableModel {
    Q_OBJECT

public:
    //--------------------constructors and destructor--------------------------------
    explicit FixtureArrayModel(Fixture** selected_fixture, DmxGateway& dmx_gtw, QObject* parent = nullptr);

    ~FixtureArrayModel();
    //-------------------------------------------------------------------------------

    //--------------------function for table model-----------------------------------
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    //-------------------------------------------------------------------------------

    //---------------------------local functions-------------------------------------
    void CreateNewFixture (int fixture_id, int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                          QString name, const ChannelType* channels);
    void DeleteFixture(int index);

    int GetFixtureIdByIndex(int index);
    Fixture* GetFixtureByIndex(int index);
    Fixture* GetFixtureByFixtureId(int fix_id);

    bool isExistingFixId(int fix_id) const;

    void AddFixtureToMap(Fixture*);

    int FixtureAmount() const;

    void Clear(); // maybe private?

    void LoadDataFromShow(QJsonObject& root);
    void SaveDataToShow(QJsonObject& root) const;
    //-------------------------------------------------------------------------------

    //---------------------------deleted functions-----------------------------------
    FixtureArrayModel() = delete;
    FixtureArrayModel(const FixtureArrayModel& dmx_gtw) = delete;
    FixtureArrayModel(FixtureArrayModel&& dmx_gtw) = delete;
    FixtureArrayModel& operator= (const FixtureArrayModel& dmx_gtw) = delete;
    FixtureArrayModel& operator= (FixtureArrayModel&& dmx_gtw) = delete;
    //-------------------------------------------------------------------------------
private:
    Fixture** selected_fixture_;
    DmxGateway& dmx_gateway_; // что если объект разрушится? ссылка будет указывать на дичь

    QVector <Fixture*> vector_fixture_; // не проинициализировал! 2) зачем через new создавать? МОЖНО СТАТИЧЕСКИ БЕЗ NEW!
    std::map <int, Fixture*> map_fixture_;

    int fixtures_amount_ = 0; // maybe unsigned?
};

#endif // FIXTUREARRAY_H
