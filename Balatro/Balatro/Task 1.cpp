#include <iostream>
#include <memory>
#include <cstdlib>

// Interfaces
class IInputGenerator {
public:
    virtual int GenerateInput() = 0;
    virtual ~IInputGenerator() = default;
};

class IScoringRule {
public:
    virtual int ComputeBaseScore(int input) = 0;
    virtual ~IScoringRule() = default;
};

class IRewardRule {
public:
    virtual int ComputeReward(int baseScore, int currentRound) = 0;
    virtual ~IRewardRule() = default;
};

// Implementasi Modifikasi 1: RandomInputGenerator menggantikan input standar
class RandomInputGenerator : public IInputGenerator {
public:
    int GenerateInput() override {
        return rand() % 10 + 1;
    }
};

class BaseScoringRule : public IScoringRule {
public:
    int ComputeBaseScore(int input) override {
        return input;
    }
};

// Implementasi Modifikasi 2: Reward logic berubah, bukan sekadar sama dengan baseScore
class DynamicRewardRule : public IRewardRule {
public:
    int ComputeReward(int baseScore, int currentRound) override {
        if (currentRound % 2 == 0) {
            return baseScore * 2; // Reward digandakan pada ronde genap
        }
        return baseScore + 2;
    }
};

