#pragma once

#include "Hand.h"
#include "HandEvaluator.h"

class IScoringRule {
public:
    virtual ~IScoringRule() = default;
    virtual int computeBaseScore(const Hand& hand) = 0;
};

class ChainScoringRule : public IScoringRule {
public:
    HandRank evaluateRank(const Hand& hand) const;
    int computeBaseScore(const Hand& hand) override;

private:
    HandEvaluatorChain evaluator;
};

int handScore(HandRank rank);
