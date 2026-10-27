#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "JokerCard.h"
#include "BlindRule.h"
#include "RewardRule.h"

class GameManager {
private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    JokerCard jokerCard;
    BlindRule blindRule;
    RewardRule rewardRule;

public:
    GameManager();
    void runSession();
};
