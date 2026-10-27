#include "RewardRule.h"

int RewardRule::earnMoney(bool win, int score) const {
    if (!win) return 0;
    return 20 + score / 10;
}
