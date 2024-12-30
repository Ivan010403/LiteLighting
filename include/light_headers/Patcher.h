#ifndef PATCHER_H
#define PATCHER_H

#include <ola/Constants.h>
#include <light_headers/FixtureArray.h> // уже есть в главном файле


class Patcher {
public:
    Patcher() = delete;

    Patcher(unsigned int cfg_univ_amount, FixtureArray& fixts, std::vector<std::vector<bool>>& cfg_univ_patching)
        : universe_amount_(cfg_univ_amount),
        all_fixtures_(fixts),
        universe_patching_(std::move(cfg_univ_patching)) // стоит ли мувать?
    {}

    ~Patcher() = default; // вызвать операцию сохранения в файл


    void PatchNewFixture(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount,
        std::string name, std::unordered_map <ChannelType, unsigned char>& channels) {

        all_fixtures_.createNewFixture(universe_id, dmx_address, channel_amount, name, channels);

        for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
            universe_patching_[universe_id][i] = false;
        }
    } // TODO: может быть слить оба метода в один?

    // проверяет, есть ли свободное место в заданной вселенной в выбранном отрезке адресов
    // только после выполнения этой функции и проверки, мы можем добавить новые устройства
    bool IsFreeAddress(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount) const { // очень много раз копируем, может быть передатть по ссылке и сверяться с ссылочным значением?
        if (universe_id > universe_amount_ - 1) return false;
        // if (dmx_address >= ola::DMX_MAX_SLOT_NUMBER) return false; // может убрать? бесполезная проверка
        if (dmx_address + channel_amount >= ola::DMX_MAX_SLOT_NUMBER) return false;

        for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
            if (!universe_patching_[universe_id][i]) return false;
        }

        return true;
    }

private:
    std::vector<std::vector<bool>> universe_patching_; // можно ли так делать? // true - свободно, false - занято
    unsigned int universe_amount_ = 0;
    FixtureArray& all_fixtures_; // подумать про доступ: нужен ли он на таком уровне? Здесь мне нужен всего один метод! Подумать, как
    // как сделать так, чтобы я пользовался только одним методом и не имел доступ к другим методам?
};

#endif // PATCHER_H
