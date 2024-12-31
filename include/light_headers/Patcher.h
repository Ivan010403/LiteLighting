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
                        std::string name, std::unordered_map <ChannelType, unsigned char>& channels);

    bool IsFreeAddress(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount) const;

private:
    std::vector<std::vector<bool>> universe_patching_; // можно ли так делать? // true - свободно, false - занято
    unsigned int universe_amount_ = 0;
    FixtureArray& all_fixtures_; // подумать про доступ: нужен ли он на таком уровне? Здесь мне нужен всего один метод! Подумать, как
    // как сделать так, чтобы я пользовался только одним методом и не имел доступ к другим методам?
};

#endif // PATCHER_H
