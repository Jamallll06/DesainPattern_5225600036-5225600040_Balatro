#pragma once

#include "Hand.h"
#include <random>

class IHandGenerator {
public:
    virtual ~IHandGenerator() = default;
    virtual Hand generateHand(int count = 8) = 0;
};

class RandomHandGenerator : public IHandGenerator {
public:
    RandomHandGenerator();
    Hand generateHand(int count = 8) override;

private:
    std::mt19937 rng;
};
