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

class ShopSystem {
public:
    void PrintOffer(int currentMoney) {
        std::cout << "[SHOP] offered: Bonus (+2) cost 2\n";
        if (currentMoney >= 2) {
            std::cout << "[SHOP] bought Bonus!\n";
        }
        else {
            std::cout << "[SHOP] skipped\n";
        }
    }
};

class RunSession {
private:
    std::unique_ptr<IInputGenerator> inputGen;
    std::unique_ptr<IScoringRule> scoringRule;
    std::unique_ptr<IRewardRule> rewardRule;
    ShopSystem shop;
    int money = 0;
    int round = 1;

public:
    RunSession(std::unique_ptr<IInputGenerator> ig,
        std::unique_ptr<IScoringRule> sr,
        std::unique_ptr<IRewardRule> rr)
        : inputGen(std::move(ig)), scoringRule(std::move(sr)), rewardRule(std::move(rr)) {
    }

    void StartRun() {
        std::cout << "=== RUN START ===\n";
        while (round <= 3) {
            std::cout << "Round " << round << "\n";

            int input = inputGen->GenerateInput();
            std::cout << "[PLAY] input generated: " << input << "\n";

            int baseScore = scoringRule->ComputeBaseScore(input);
            std::cout << "[SCORE] base score: " << baseScore << "\n";

            int reward = rewardRule->ComputeReward(baseScore, round);
            money += reward;
            std::cout << "[REWARD] gain: " << reward << " | money: " << money << "\n";

            shop.PrintOffer(money);

            round++;
        }
        std::cout << "=== RUN END ===\nFinal money: " << money << "\n";
    }
};

int main() {
    RunSession game(
        std::make_unique<RandomInputGenerator>(),
        std::make_unique<BaseScoringRule>(),
        std::make_unique<DynamicRewardRule>()
    );
    game.StartRun();
    return 0;
}