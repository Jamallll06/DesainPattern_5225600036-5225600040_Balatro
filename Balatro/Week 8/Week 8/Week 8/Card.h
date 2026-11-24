#pragma once

#include <string>

struct Card {
    int rank;
    char suit;

    bool operator==(const Card& other) const {
        return rank == other.rank && suit == other.suit;
    }
};

inline std::string rankString(int rank) {
    if (rank >= 2 && rank <= 10) {
        return std::to_string(rank);
    }

    switch (rank) {
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    case 14: return "A";
    default: return "?";
    }
}

inline std::string cardString(const Card& card) {
    return rankString(card.rank) + card.suit;
}
