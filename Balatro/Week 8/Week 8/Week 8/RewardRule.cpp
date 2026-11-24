#include "RewardRule.h"
#include <algorithm>

int DynamicRewardRule::computeReward(int baseScore, int round) {
    int reward = baseScore / 10;
    if (round % 2 == 0) reward *= 2;
    return std::max(1, reward);
}
