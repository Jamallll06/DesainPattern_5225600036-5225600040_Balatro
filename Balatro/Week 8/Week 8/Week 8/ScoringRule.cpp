#include "ScoringRule.h"

int ScoringRule::scoreHand(const Hand& hand) const {
    int score = 0;
    for (const Card& card : hand.cards) {
        score += card.rank;
    }
    return score;
}
