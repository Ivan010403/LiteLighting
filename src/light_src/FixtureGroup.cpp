#include "light_headers/FixtureGroup.h"

FixtureGroup::FixtureGroup(unsigned int fixture_id, std::string name, const std::vector<Fixture*>& group_fxtrs) :
    group_fxtrs_(std::move(group_fxtrs)),
    Fixture(fixture_id, name) {}

void FixtureGroup::ChangeData(ChannelType channel_type, int value) {
    for (const auto& fxtr : group_fxtrs_) {
        *(fxtr->channels_)[channel_type] = value;
        fxtr->SendDmxData();
    }
}
