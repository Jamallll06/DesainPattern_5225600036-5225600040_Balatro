#pragma once

#include "Hand.h"
#include "HandRank.h"

class HandEvaluatorChain {
public:
    HandRank evaluate(const Hand& hand) const;
};
