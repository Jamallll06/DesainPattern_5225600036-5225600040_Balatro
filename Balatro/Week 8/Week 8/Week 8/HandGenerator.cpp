#include "HandGenerator.h"
#include <algorithm>
#include <random>
#include <vector>

Hand HandGenerator::generateHand() {
    std::vector<Card> deck;
    const char suits[] = {'H', 'D', 'C', 'S'};

    for (char suit : suits) {
        for (int rank = 2; rank <= 14; ++rank) {
            deck.push_back({rank, suit});
        }
    }

    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::shuffle(deck.begin(), deck.end(), rng);

    Hand hand;
    for (int i = 0; i < 5; ++i) {
        hand.cards.push_back(deck[i]);
    }
    return hand;
}
