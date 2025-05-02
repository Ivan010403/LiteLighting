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
            case 1: return QString::fromStdString(fixture->name_);
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
        switch (index.column()) {
            // ПРОВЕРИТЬ НА СУЖЕНИЯ ДАННЫХ, У МЕНЯ ТАМ UINT8_T
            case 0:
                fixture->fixture_id_ = value.toInt();
                break;
            case 1:
                fixture->name_ = value.toString().toStdString();
                break;
            case 2:
            { // чтобы не было ошибки из-за скоупа list --- придумать как сделать лучше
                QVariantList list = value.toList();

                // if (list.size() < 2) return false;

                // // 3. Проверяем конвертацию в uint8_t
                // bool ok1, ok2;
                // quint32 universe = list[0].toUInt(&ok1);
                // quint32 dmx = list[1].toUInt(&ok2);

                // if (!ok1 || !ok2 || universe > UINT8_MAX || dmx > UINT8_MAX) {
                //     return false; // Некорректные данные
                // }

                fixture->universe_id_ = list[0].toInt();
                fixture->dmx_address_ = list[1].toInt();

                // fixture->universe_id_ = static_cast<uint8_t>(universe);
                // fixture->dmx_address_ = static_cast<uint8_t>(dmx);
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
unsigned int FixtureArrayModel::GetFixtureIdByIndex(int index) {
    return vector_fixture_[index]->GetFixtureId();
}

Fixture* FixtureArrayModel::GetFixtureByIndex(int index) {
    return vector_fixture_[index];
}


int FixtureArrayModel::FixtureAmount() const {
    return fixtures_amount_;
}

int FixtureArrayModel::GroupAmount() const {
    return groups_anount_;
}
