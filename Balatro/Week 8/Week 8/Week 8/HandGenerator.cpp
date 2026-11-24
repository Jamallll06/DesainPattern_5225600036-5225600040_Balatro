#include "HandGenerator.h"
#include <algorithm>
#include <random>
#include <vector>

RandomHandGenerator::RandomHandGenerator() : rng(std::random_device{}()) {}

Hand RandomHandGenerator::generateHand(int count) {
    std::vector<Card> deck;
    const char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits) {
        for (int rank = 2; rank <= 14; ++rank) deck.push_back({rank, suit});
    }

    std::shuffle(deck.begin(), deck.end(), rng);
    Hand hand;
    const int drawCount = std::max(0, std::min(count, static_cast<int>(deck.size())));
    hand.cards.assign(deck.begin(), deck.begin() + drawCount);
    return hand;
}
