#include "light_headers/FixtureArray.h"

int FixtureArrayModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return fixtures_amount_;
}

#define COLUMN_AMOUNT 6 // ЗАМЕНИТЬ!!!

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
            case 1: return QString::fromStdString(fixture->name_);
            case 2: return fixture->universe_id_;
            case 3: return fixture->group_id_;
            case 4: return fixture->dmx_address_;
            case 5: return fixture->channel_amount_;
        }
    }

    return QVariant();
}

QVariant FixtureArrayModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "FixID";
            case 1: return "Name";
            case 2: return "Universe";
            case 3: return "Group";
            case 4: return "Address";
            case 5: return "Channel";

        }
    }
    return QVariant();
}

bool FixtureArrayModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    // if (role == Qt::EditRole && index.isValid()) {
    //     Fixture* fixture = vector_fixture_[index.row()];
    //     switch (index.column()) {
    //         // ПРОВЕРИТЬ НА СУЖЕНИЯ ДАННЫХ, У МЕНЯ ТАМ UINT8_T
    //         case 0:
    //             fixture->fixture_id_ = value.toInt();
    //             break;
    //         case 1:
    //             fixture->name_ = value.toString();
    //             break;
    //         case 2:
    //             fixture->universe_id_ = value.toInt();
    //             break;
    //         case 3:
    //             fixture->group_id_ = value.toInt();
    //             break;
    //         case 4:
    //             fixture->dmx_address_ = value.toInt();
    //             break;
    //         case 5:
    //             fixture->channel_amount_ = value.toInt();
    //             break;
    //         default:
    //             return false;
    //     }
    //     emit dataChanged(index, index);
    //     return true;
    // }
    return false;
}

Qt::ItemFlags FixtureArrayModel::flags(const QModelIndex& index) const {
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}


void FixtureArrayModel::CreateNewFixture(unsigned int fixture_id, unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
                                        std::string name, const ChannelType* channels)
{
    ++fixtures_amount_;
    beginInsertRows(QModelIndex(), vector_fixture_.size(), vector_fixture_.size());
    vector_fixture_.append(new Fixture(fixture_id, universe_id, dmx_address, channel_amount, name,
                                       channels, dmx_gateway_.GetBuffer(universe_id)));
    endInsertRows();
}


// refactor!!!
Fixture* FixtureArrayModel::GetFixtureByIndex(int index) {
    return vector_fixture_[index];
}

int FixtureArrayModel::FixtureAmount() const {
    return fixtures_amount_;
}

int FixtureArrayModel::GroupAmount() const {
    return groups_anount_;
}
