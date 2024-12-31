#include "light_headers/Patcher.h"

void Patcher::PatchNewFixture(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
    std::string name, std::unordered_map <ChannelType, unsigned char>& channels)
{
    all_fixtures_.createNewFixture(universe_id, dmx_address, channel_amount, name, channels);

    for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
        universe_patching_[universe_id][i] = false;
    }
} // TODO: может быть слить оба метода в один?


// проверяет, есть ли свободное место в заданной вселенной в выбранном отрезке адресов
// только после выполнения этой функции и проверки, мы можем добавить новые устройства
bool Patcher::IsFreeAddress(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount) const { // очень много раз копируем, может быть передатть по ссылке и сверяться с ссылочным значением?
    if (universe_id > universe_amount_ - 1) return false;
    // if (dmx_address >= ola::DMX_MAX_SLOT_NUMBER) return false; // может убрать? бесполезная проверка
    if (dmx_address + channel_amount >= ola::DMX_MAX_SLOT_NUMBER) return false;

    for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
        if (!universe_patching_[universe_id][i]) return false;
    }

    return true;
}
