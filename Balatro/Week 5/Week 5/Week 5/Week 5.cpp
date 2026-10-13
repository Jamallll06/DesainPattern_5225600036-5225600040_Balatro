#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// =====================================================
// 1. CARD DAN HAND
// =====================================================

struct Card {
    int rank;
    char suit;
};

class Hand {
public:
    vector<Card> cards;

    Hand() = default;

    Hand(initializer_list<Card> input) : cards(input) {}
};

string rankString(int rank) {
    if (rank >= 2 && rank <= 10)
        return to_string(rank);

    switch (rank) {
    case 11: return "J";
    case 12: return "Q";
    case 13: return "K";
    case 14: return "A";
    default: return "?";
    }
}

string cardString(const Card& card) {
    return rankString(card.rank) + card.suit;
}

string handString(const Hand& hand) {
    string result;

    for (size_t i = 0; i < hand.cards.size(); i++) {
        if (i > 0) result += " ";
        result += cardString(hand.cards[i]);
    }

    return result;
}

// =====================================================
// 2. HAND RANK
// =====================================================

enum class HandRank {
    None,
    HighCard,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
    FiveOfAKind,
    FlushHouse,
    FlushFive
};

string handRankName(HandRank rank) {
    switch (rank) {
    case HandRank::HighCard: return "High Card";
    case HandRank::Pair: return "Pair";
    case HandRank::TwoPair: return "Two Pair";
    case HandRank::ThreeOfAKind: return "Three of a Kind";
    case HandRank::Straight: return "Straight";
    case HandRank::Flush: return "Flush";
    case HandRank::FullHouse: return "Full House";
    case HandRank::FourOfAKind: return "Four of a Kind";
    case HandRank::StraightFlush: return "Straight Flush";
    case HandRank::RoyalFlush: return "Royal Flush";
    case HandRank::FiveOfAKind: return "Five of a Kind";
    case HandRank::FlushHouse: return "Flush House";
    case HandRank::FlushFive: return "Flush Five";
    default: return "None";
    }
}

// =====================================================
// 3. EVALUASI KOMBINASI
// =====================================================

HandRank evaluateHand(const Hand& hand) {
    if (hand.cards.size() != 5)
        return HandRank::None;

    map<int, int> rankCount;
    map<char, int> suitCount;

    for (const Card& card : hand.cards) {
        if (card.rank < 2 || card.rank > 14)
            return HandRank::None;

        if (card.suit != 'H' && card.suit != 'D' &&
            card.suit != 'C' && card.suit != 'S')
            return HandRank::None;

        rankCount[card.rank]++;
        suitCount[card.suit]++;
    }

    bool flush = suitCount.size() == 1;
    bool fiveKind = false;
    bool fourKind = false;
    bool threeKind = false;
    int pairs = 0;

    for (const auto& item : rankCount) {
        if (item.second == 5) fiveKind = true;
        if (item.second == 4) fourKind = true;
        if (item.second == 3) threeKind = true;
        if (item.second == 2) pairs++;
    }

    bool fullHouse = threeKind && pairs >= 1;
    bool flushHouse = fullHouse && flush;
    bool flushFive = fiveKind && flush;

    vector<int> ranks;

    for (const auto& item : rankCount)
        ranks.push_back(item.first);

    bool straight = false;

    if (ranks.size() == 5) {
        straight = true;

        for (int i = 1; i < 5; i++) {
            if (ranks[i] != ranks[i - 1] + 1)
                straight = false;
        }

        if (ranks == vector<int>{2, 3, 4, 5, 14})
            straight = true;
    }

    bool straightFlush = straight && flush;

    bool royalFlush =
        straightFlush &&
        rankCount.count(10) &&
        rankCount.count(11) &&
        rankCount.count(12) &&
        rankCount.count(13) &&
        rankCount.count(14);

    if (flushFive) return HandRank::FlushFive;
    if (flushHouse) return HandRank::FlushHouse;
    if (fiveKind) return HandRank::FiveOfAKind;
    if (royalFlush) return HandRank::RoyalFlush;
    if (straightFlush) return HandRank::StraightFlush;
    if (fourKind) return HandRank::FourOfAKind;
    if (fullHouse) return HandRank::FullHouse;
    if (flush) return HandRank::Flush;
    if (straight) return HandRank::Straight;
    if (threeKind) return HandRank::ThreeOfAKind;
    if (pairs >= 2) return HandRank::TwoPair;
    if (pairs == 1) return HandRank::Pair;

    return HandRank::HighCard;
}

// =====================================================
// 4. POKER HAND CHECKER
// =====================================================

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

public:
    virtual ~PokerHandChecker() = default;

    virtual HandRank check(const Hand& hand) = 0;

    void setNext(PokerHandChecker* next) {
        nextChecker = next;
    }
};

HandRank checkSpecific(const Hand& hand, HandRank expected) {
    HandRank result = evaluateHand(hand);
    return result == expected ? result : HandRank::None;
}

#define CREATE_CHECKER(ClassName, RankName) \
class ClassName : public PokerHandChecker { \
public: \
    HandRank check(const Hand& hand) override { \
        return checkSpecific(hand, HandRank::RankName); \
    } \
};

CREATE_CHECKER(HighCardChecker, HighCard)
CREATE_CHECKER(PairChecker, Pair)
CREATE_CHECKER(TwoPairChecker, TwoPair)
CREATE_CHECKER(ThreeOfAKindChecker, ThreeOfAKind)
CREATE_CHECKER(StraightChecker, Straight)
CREATE_CHECKER(FlushChecker, Flush)
CREATE_CHECKER(FullHouseChecker, FullHouse)
CREATE_CHECKER(FourOfAKindChecker, FourOfAKind)
CREATE_CHECKER(StraightFlushChecker, StraightFlush)
CREATE_CHECKER(RoyalFlushChecker, RoyalFlush)
CREATE_CHECKER(FiveOfAKindChecker, FiveOfAKind)
CREATE_CHECKER(FlushHouseChecker, FlushHouse)
CREATE_CHECKER(FlushFiveChecker, FlushFive)

// =====================================================
// 5. SCORING
// =====================================================

int handScore(HandRank rank) {
    switch (rank) {
    case HandRank::HighCard: return 15;
    case HandRank::Pair: return 40;
    case HandRank::TwoPair: return 96;
    case HandRank::ThreeOfAKind: return 135;
    case HandRank::Straight: return 260;
    case HandRank::Flush: return 284;
    case HandRank::FullHouse: return 292;
    case HandRank::FourOfAKind: return 560;
    case HandRank::StraightFlush: return 1080;
    case HandRank::RoyalFlush: return 1208;
    case HandRank::FiveOfAKind: return 1740;
    case HandRank::FlushHouse: return 2422;
    case HandRank::FlushFive: return 2960;
    default: return 0;
    }
}