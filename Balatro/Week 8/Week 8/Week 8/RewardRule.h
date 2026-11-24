#pragma once

class IRewardRule {
public:
    virtual ~IRewardRule() = default;
    virtual int computeReward(int baseScore, int round) = 0;
};

class DynamicRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore, int round) override;
};
