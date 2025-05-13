#include "light_headers/FixtureArray.h"

FixtureArrayModel::FixtureArrayModel(Fixture** selected_fixture, DmxGateway& dmx_gtw, QObject* parent) :
    selected_fixture_(selected_fixture),
    dmx_gateway_(dmx_gtw),
    QAbstractTableModel(parent) {}

FixtureArrayModel::~FixtureArrayModel() {
    for (int i = 0; i < vector_fixture_.size(); ++i) {
        delete vector_fixture_[i];
    }
}

int FixtureArrayModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return fixtures_amount_;
}

#define COLUMN_AMOUNT 5  // ЗАМЕНИТЬ!!!

int FixtureArrayModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return COLUMN_AMOUNT;
}

QVariant FixtureArrayModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= fixtures_amount_ || index.column() >= COLUMN_AMOUNT)
        return QVariant();

    const Fixture* fixture = vector_fixture_[index.row()];

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
            case 0: return fixture->fixture_id_;
            case 1: return fixture->name_;
            case 2: return QString::number(fixture->universe_id_) + "." + QString::number(fixture->dmx_address_);
            case 3: return fixture->channel_amount_;
            case 4: return fixture->group_id_;
        }
    }

    return QVariant();
}

QVariant FixtureArrayModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "FixID";
            case 1: return "Name";
            case 2: return "Address";
            case 3: return "Channel";
            case 4: return "Group";
        }
    }
    return QVariant();
}

bool FixtureArrayModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (role == Qt::EditRole && index.isValid()) {
        Fixture* fixture = vector_fixture_[index.row()];
        *selected_fixture_ = fixture;

        emit Mediator::instance().SelectingFixture();
        emit Mediator::instance().SelectingCommand();

        qDebug() << "FixtureArrayModel --> selected fixture id = " << (*selected_fixture_)->GetFixtureId();

        switch (index.column()) {
            case 0:
            {
                int value_ = value.toInt();

                while ((isExistingFixId(value_)) && (fixture->fixture_id_ != value_)) {
                    ++value_;
                }

                fixture->fixture_id_ = value_;
                break;
            }
            case 1:
                fixture->name_ = value.toString();
                break;
            case 2:
            {
                QVariantList list = value.toList();
                fixture->universe_id_ = list[0].toInt();
                fixture->dmx_address_ = list[1].toInt();

                fixture->SetDmxBuffer(dmx_gateway_.GetBuffer(fixture->universe_id_));
                break;
            }
            case 3:
                fixture->channel_amount_ = value.toInt();
                break;
            case 4:
                fixture->group_id_ = value.toInt();
                break;
            default:
                return false;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags FixtureArrayModel::flags(const QModelIndex& index) const {
    if (index.column() >= 3) {
        return QAbstractTableModel::flags(index) & ~Qt::ItemIsEditable;
    }
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}


void FixtureArrayModel::CreateNewFixture(int fixture_id, int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                                        QString name, const ChannelType* channels)
{
    ++fixtures_amount_;
    beginInsertRows(QModelIndex(), vector_fixture_.size(), vector_fixture_.size());

    Fixture* fxtr = new Fixture(fixture_id, universe_id, dmx_address, channel_amount, name,
                                channels, dmx_gateway_.GetBuffer(universe_id));
    vector_fixture_.append(fxtr);
    map_fixture_[fixture_id] = fxtr;

    endInsertRows();

    qDebug() << "FixtureArrayModel::CreateNewFixture() --> создалась новая фикстура с id = " << fixture_id << " всего фикстур " << fixtures_amount_;
}

void FixtureArrayModel::DeleteFixture(int index) {
    emit Mediator::instance().DeletingFixture(vector_fixture_[index]);

    int for_debug = GetFixtureIdByIndex(index); // удалить

    beginRemoveRows(QModelIndex(), index, index);
    map_fixture_.erase(GetFixtureIdByIndex(index));

    delete vector_fixture_[index];
    vector_fixture_.removeAt(index);

    endRemoveRows();

    --fixtures_amount_;

    qDebug() << "FixtureArrayModel::DeleteFixture() --> удалилась фикстура с index = " << index << "и id = " << for_debug << " всего фикстур = " << fixtures_amount_;

}


// refactor!!!
int FixtureArrayModel::GetFixtureIdByIndex(int index) {
    return vector_fixture_[index]->GetFixtureId();
}

Fixture* FixtureArrayModel::GetFixtureByIndex(int index) {
    return vector_fixture_[index];
}

Fixture* FixtureArrayModel::GetFixtureByFixtureId(int fix_id) {
    return map_fixture_[fix_id];
}

bool FixtureArrayModel::isExistingFixId(int fix_id) const {
    return map_fixture_.count(fix_id) > 0;
}


void FixtureArrayModel::AddFixtureToMap(Fixture* fxtr) {
    map_fixture_[fxtr->GetFixtureId()] = fxtr;
}

int FixtureArrayModel::FixtureAmount() const {
    return fixtures_amount_;
}

void FixtureArrayModel::Clear() {
    for (int i = 0; i < vector_fixture_.size(); ++i) {
        delete vector_fixture_[i];
    }
    vector_fixture_.clear();
    map_fixture_.clear();
    fixtures_amount_ = 0;

    qDebug() << "FixtureArrayModel::Clear() --> все фикстуры удалены. vec.size() = " << vector_fixture_.size() << "map.size() = " <<  map_fixture_.size();
}

void FixtureArrayModel::LoadDataFromShow(QJsonObject& root) {
    Clear();

    emit Mediator::instance().CreationGroup(-1, nullptr, QStringLiteral(""));

    QJsonArray fixtures_array = root["fixtures"].toArray();

    for (const QJsonValue& val : fixtures_array) {
        QJsonObject fixture = val.toObject();

        // Извлекаем данные
        int fix_id = fixture["fix_id"].toInt();
        int univ_id = fixture["univ_id"].toInt();
        uint16_t dmx_addr = fixture["dmx_addr"].toInt();
        uint16_t chan_amount = fixture["chan_amount"].toInt();
        const QString name = fixture["name"].toString();
        int group_id = fixture["group_id"].toInt();
        const QString group_name = fixture["group_name"].toString();

        ChannelType channel_types[chan_amount];

        QJsonArray channel_types_json = fixture["channels_type"].toArray();
        QJsonArray channel_values_json = fixture["channels_value"].toArray();

        for (int i = 0; i < channel_types_json.size(); ++i) {
            channel_types[i] = static_cast<ChannelType>(channel_types_json[i].toInt());
        }

        CreateNewFixture(fix_id, univ_id, dmx_addr, chan_amount, name, channel_types);

        vector_fixture_[fixtures_amount_-1]->group_id_ = group_id;
        vector_fixture_[fixtures_amount_-1]->group_name_ = group_name;

        if (group_id != 0) emit Mediator::instance().CreationGroup(group_id, vector_fixture_[fixtures_amount_-1], group_name);

        for (int i = 0; i < channel_values_json.size(); ++i) {
            vector_fixture_[fixtures_amount_-1]->ChangeData(channel_types[i], channel_values_json[i].toInt());
        }
    }

    qDebug() << "FixtureArrayModel::LoadDataFromShow() --> Данные загружены. Amount = " << fixtures_amount_ << "vec.size() = " << vector_fixture_.size() << "map.size() = " <<  map_fixture_.size();
}

void FixtureArrayModel::SaveDataToShow(QJsonObject& root) const {
    QJsonArray json_array;

    for (const auto& var : vector_fixture_) {
        json_array.append(var->SaveDataToShow());
    }

    root["fixtures"] = json_array;

    qDebug() << "FixtureArrayModel::SaveDataToShow()";
}
