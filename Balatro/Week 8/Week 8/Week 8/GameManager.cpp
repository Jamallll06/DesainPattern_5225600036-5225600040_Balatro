#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
    : jokerCard(10), blindRule(100) {}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    // Step 1: Generate cards
    Hand hand = handGenerator.generateHand();

    // Step 2: Player plays selected hand
    handPlayer.playHand(hand);

    // Step 3: Calculate base score
    int score = scoringRule.scoreHand(hand);
    std::cout << "Base score: " << score << '\n';

    // Step 4: Notify Joker observer
    jokerCard.onHandPlayed(score);

    // Step 5: Joker modifies score
    score = jokerCard.modifyScore(score);
    std::cout << "Final score: " << score << '\n';

    // Step 6: Check win / lose
    bool win = blindRule.checkBlind(score);
    std::cout << (win ? "Status: WIN\n" : "Status: LOSE\n");

    // Step 7: Calculate reward
    int reward = rewardRule.earnMoney(win, score);
    std::cout << "Money gained: " << reward << '\n';

    std::cout << "=== Run Ended ===\n";
}
