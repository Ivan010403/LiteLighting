#ifndef PATCHER_H
#define PATCHER_H
#include <vector> // проверить мало ли уже где-то заинклудили
#include <stdint.h> // проверить мало ли уже где-то заинклудили
#include <ola/Constants.h>

class Patcher {
public:
    Patcher() : universe_patching_(1, std::vector<bool>(ola::DMX_MAX_SLOT_NUMBER, true))  {

    }

    ~Patcher() {

    }

    // проверяет, есть ли свободное место в заданной вселенной в выбранном отрезке адресов
    // только после выполнения этой функции и проверки, мы можем добавить новые устройства
    bool IsFreeAddress(unsigned int universe_id, uint16_t dmx_address, uint16_t channel_amount) {
        if (universe_id > universe_amount_ - 1) return false;
        if (dmx_address >= ola::DMX_MAX_SLOT_NUMBER) return false;
        if (dmx_address + channel_amount >= ola::DMX_MAX_SLOT_NUMBER) return false;

        for (uint16_t i = dmx_address; i < dmx_address + channel_amount; ++i) {
            if (!universe_patching_[universe_id][i]) return false;
        }

        return true;
    }
protected:

private:
    unsigned int universe_amount_ = 1;
    std::vector<std::vector<bool>> universe_patching_; // можно ли так делать?
};

#endif // PATCHER_H
