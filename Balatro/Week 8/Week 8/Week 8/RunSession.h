#pragma once

#include "BlindRule.h"
#include "HandEvaluator.h"
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "HandScoring.h"
#include "RewardRule.h"
#include "ShopSystem.h"
#include <memory>

class RunSession {
public:
    RunSession(std::unique_ptr<IHandGenerator> handGenerator,
        std::unique_ptr<IScoringRule> scoringRule,
        std::unique_ptr<IRewardRule> rewardRule);
    void startRun();

private:
    std::unique_ptr<IHandGenerator> handGenerator;
    std::unique_ptr<IScoringRule> scoringRule;
    std::unique_ptr<IRewardRule> rewardRule;
    HandPlayer handPlayer;
    HandEvaluatorChain handEvaluator;
    BlindRule blind;
    ShopSystem shop;
    int money = 0;
};
