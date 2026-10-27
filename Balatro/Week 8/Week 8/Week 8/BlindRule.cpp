#include "BlindRule.h"

BlindRule::BlindRule(int target)
    : targetScore(target >= 0 ? target : 100) {}

bool BlindRule::checkBlind(int score) const {
    return score >= targetScore;
}

void BlindRule::setTargetScore(int target) {
    if (target >= 0) targetScore = target;
}

int BlindRule::getTargetScore() const {
    return targetScore;
}
