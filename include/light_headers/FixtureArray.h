#ifndef FIXTUREARRAY_H
#define FIXTUREARRAY_H
#include <QAbstractTableModel>
#include <QVector>

#include "light_headers/Fixture.h"
#include "light_headers/DmxGateway.h"

class FixtureArrayModel : public QAbstractTableModel {
    Q_OBJECT

public:
    //--------------------constructors and destructor--------------------------------
    explicit FixtureArrayModel(Fixture** selected_fixture, DmxGateway& dmx_gtw, QObject* parent = nullptr) : selected_fixture_(selected_fixture), dmx_gateway_(dmx_gtw), QAbstractTableModel(parent) {}

    ~FixtureArrayModel() {
        for (int i = 0; i < vector_fixture_.size(); ++i) { // вот тут могут быть проблемы если группа появится, ибо группа не в счётчике фикстур
            delete vector_fixture_[i]; // аккуратнее
        }
    }
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
    unsigned int GetFixtureIdByIndex(int index);
    void CreateNewFixture (unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                          std::string name, const ChannelType* channels);
    int FixtureAmount() const;
    int GroupAmount() const;
    Fixture* GetFixtureByIndex(int index);
    //-------------------------------------------------------------------------------

    //---------------------------deleted functions-----------------------------------
    FixtureArrayModel() = delete;
    FixtureArrayModel(const FixtureArrayModel& dmx_gtw) = delete;
    FixtureArrayModel(FixtureArrayModel&& dmx_gtw) = delete;
    FixtureArrayModel& operator= (const FixtureArrayModel& dmx_gtw) = delete;
    FixtureArrayModel& operator= (FixtureArrayModel&& dmx_gtw) = delete;
    //-------------------------------------------------------------------------------
private:
    QVector <Fixture*> vector_fixture_; // не проинициализировал! 2) зачем через new создавать? МОЖНО СТАТИЧЕСКИ БЕЗ NEW!
    int fixtures_amount_ = 0; // maybe unsigned?
    int groups_anount_ = 0;

    Fixture** selected_fixture_;

    DmxGateway& dmx_gateway_; // что если объект разрушится? ссылка будет указывать на дичь
};

#endif // FIXTUREARRAY_H
