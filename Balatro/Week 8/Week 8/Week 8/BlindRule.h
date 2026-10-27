#pragma once

class BlindRule {
private:
    int targetScore;

public:
    explicit BlindRule(int target = 100);

    bool checkBlind(int score) const;
    void setTargetScore(int target);
    int getTargetScore() const;
};
