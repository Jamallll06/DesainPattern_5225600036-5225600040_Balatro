
#include <iostream>
using namespace std;

// Representasi kartu dan tangan
class Hand {
    // Detail kartu belum diperlukan
};

// Jenis kombinasi poker
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

// Kelas dasar Poker Hand Checker
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

// 1. High Card
class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::HighCard;
    }
};

// 2. Pair
class PairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::Pair;
    }
};

// 3. Two Pair
class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::TwoPair;
    }
};

// 4. Three of a Kind
class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::ThreeOfAKind;
    }
};

// 5. Straight
class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::Straight;
    }
};

// 6. Flush
class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        return HandRank::Flush;
    }
};

