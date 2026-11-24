#include "RunSession.h"
#include <algorithm>
#include <iostream>
#include <utility>

RunSession::RunSession(std::unique_ptr<IHandGenerator> handGeneratorValue,
    std::unique_ptr<IScoringRule> scoringRuleValue,
    std::unique_ptr<IRewardRule> rewardRuleValue)
    : handGenerator(std::move(handGeneratorValue)),
      scoringRule(std::move(scoringRuleValue)),
      rewardRule(std::move(rewardRuleValue)) {}

void RunSession::startRun() {
    std::cout << "\n=== RUN START ===\n";
    for (int round = 1; round <= 3; ++round) {
        const int target = blind.getTarget(round);
        std::cout << "\nRound " << round << " - " << blind.getName(round)
            << " (target " << target << ")\n";

        const Hand drawnHand = handGenerator->generateHand(8);
        std::cout << "[DEAL] drawn cards (" << drawnHand.cards.size() << "): "
            << handString(drawnHand) << "\n";

        const Hand playedHand = handPlayer.playHand(drawnHand);
        if (playedHand.cards.empty()) {
            std::cout << "Run dihentikan.\n";
            return;
        }

        std::cout << "[PLAY] chosen hand (" << playedHand.cards.size() << " kartu): "
            << handString(playedHand) << "\n";
        const HandRank rank = handEvaluator.evaluate(playedHand);
        const int score = scoringRule->computeBaseScore(playedHand);
        std::cout << "[SCORE] " << handRankName(rank) << " | base score: " << score;

        const bool won = blind.checkBlind(score, round);
        std::cout << (won ? " (blind cleared)\n" : " (blind failed)\n");

        int reward = rewardRule->computeReward(score, round);
        if (!won) reward = std::max(1, reward / 10);
        money += reward;
        std::cout << "[REWARD] gain: " << reward << " | money: " << money << "\n";
        shop.printOffer(money);
    }

    std::cout << "\n=== RUN END ===\nFinal money: " << money << "\n";
}
