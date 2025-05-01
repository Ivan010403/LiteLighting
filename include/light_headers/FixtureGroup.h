#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include "./Fixture.h"

class FixtureGroup : public Fixture {
public:
    explicit FixtureGroup(unsigned int fixture_id, std::string name, const std::vector<Fixture*>& group_fxtrs) :
        group_fxtrs_(std::move(group_fxtrs)),
        Fixture(fixture_id, name) {}

    ~FixtureGroup() override = default;

    void ChangeData(ChannelType channel_type, int value) override {
        for (const auto& fxtr : group_fxtrs_) {
            *(fxtr->channels_)[channel_type] = value;
            fxtr->SendDmxData();
        }
    }

private:
    std::vector<Fixture*> group_fxtrs_;
};

#endif // FIXTUREGROUP_H
