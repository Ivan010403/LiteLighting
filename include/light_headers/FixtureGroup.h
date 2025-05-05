#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include "./Mediator.h"

class FixtureGroup : public Fixture {
public:
    explicit FixtureGroup(int fixture_id, std::string name, const std::vector<Fixture*>& group_fxtrs);

    explicit FixtureGroup(int fixture_id);

    ~FixtureGroup() override = default;

    void ChangeData(ChannelType channel_type, int value) override;

    void AddFixture(Fixture*) override;

private:
    void onDeletedFixture(Fixture* fxtr);

private:
    std::vector<Fixture*> group_fxtrs_;
};

#endif // FIXTUREGROUP_H
