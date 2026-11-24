#include "BlindRule.h"

std::string BlindRule::getName(int round) const {
    if (round == 1) return "Small Blind";
    if (round == 2) return "Big Blind";
    return "Boss Blind";
}

int BlindRule::getTarget(int round) const {
    if (round == 1) return 40;
    if (round == 2) return 70;
    return 100;
}

bool BlindRule::checkBlind(int score, int round) const {
    return score >= getTarget(round);
}
