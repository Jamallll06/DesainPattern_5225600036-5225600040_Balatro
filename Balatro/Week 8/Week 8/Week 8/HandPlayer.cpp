#include "HandPlayer.h"
#include <iostream>

void HandPlayer::playHand(const Hand& hand) const {
    std::cout << "Kartu yang dimainkan:\n";
    for (const Card& card : hand.cards) {
        std::cout << "  Rank " << card.rank << ", Suit " << card.suit << '\n';
    }
}
