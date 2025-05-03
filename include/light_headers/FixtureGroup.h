#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include "./Fixture.h"

class FixtureGroup : public Fixture {
public:
    explicit FixtureGroup(unsigned int fixture_id, std::string name, const std::vector<Fixture*>& group_fxtrs);

    ~FixtureGroup() override = default;

    void ChangeData(ChannelType channel_type, int value) override;

    bool SaveDataToShow() const override;
private:
    std::vector<Fixture*> group_fxtrs_;
};

#endif // FIXTUREGROUP_H
