#pragma once

#include <string>

class BlindRule {
public:
    std::string getName(int round) const;
    int getTarget(int round) const;
    bool checkBlind(int score, int round) const;
};
