#ifndef FIXTUREGROUP_H
#define FIXTUREGROUP_H

#include "./Mediator.h"

class FixtureGroup : public Fixture {
public:
    explicit FixtureGroup(int fixture_id, const std::vector<Fixture*>& group_fxtrs, const QString& group_name);

    explicit FixtureGroup(int fixture_id, const QString& group_name);

    ~FixtureGroup() override;

    void ChangeData(ChannelType channel_type, int value) override;

    void AddFixture(Fixture*) override;

    void DeleteFixture(Fixture* fxtr) override;

    bool isHaveChannel(ChannelType type) const override;

private:
    std::vector<Fixture*> group_fxtrs_;

    QString group_name_;
};

#endif // FIXTUREGROUP_H
