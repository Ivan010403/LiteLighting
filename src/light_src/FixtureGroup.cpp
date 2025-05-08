#include "light_headers/FixtureGroup.h"

FixtureGroup::FixtureGroup(int fixture_id, const std::vector<Fixture*>& group_fxtrs, const QString& group_name) :
    group_fxtrs_(std::move(group_fxtrs)),
    group_name_(group_name),
    Fixture(fixture_id * 100)
{
    for (auto& var : group_fxtrs_) {
        var->group_id_ = fixture_id;
        var->group_name_ = group_name_;
    }
    qDebug() << "FixtureGroup::FixtureGroup() --> группа создалась";
}

FixtureGroup::FixtureGroup(int fixture_id, const QString& group_name) : group_name_(group_name), Fixture(fixture_id * 100) {
    qDebug() << "FixtureGroup::FixtureGroup(int fixture_id) --> группа создалась";
}

void FixtureGroup::DeleteFixture(Fixture* fxtr) {
    for (int i = 0; i < group_fxtrs_.size(); ++i) {
        if (*group_fxtrs_[i] == *fxtr) {
            group_fxtrs_.erase(group_fxtrs_.begin() + i);
            qDebug() << "FixtureGroup::onDeletedFixture --> удалил фикстуру из группы ";
            break;
        }
    }
}

void FixtureGroup::AddFixture(Fixture* fxtr) {
    group_fxtrs_.push_back(fxtr);
}

void FixtureGroup::ChangeData(ChannelType channel_type, int value) {
    for (const auto& fxtr : group_fxtrs_) {
        *(fxtr->channels_)[channel_type] = value;
        fxtr->SendDmxData();
    }
}

bool FixtureGroup::isHaveChannel(ChannelType type) const {
    for (const auto& fxtr : group_fxtrs_) {
        if (!fxtr->isHaveChannel(type)) return false;
    }
    return true;
}

