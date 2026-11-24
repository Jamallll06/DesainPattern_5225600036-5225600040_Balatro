#include "Hand.h"

std::string handString(const Hand& hand) {
    std::string result;
    for (std::size_t i = 0; i < hand.cards.size(); ++i) {
        if (i > 0) result += " ";
        result += cardString(hand.cards[i]);
    }
    return result;
}
