#include "HandEvaluator.h"
#include <map>
#include <vector>

namespace {
struct HandStats {
    bool valid = false;
    bool flush = false;
    bool straight = false;
    bool royal = false;
    bool fiveKind = false;
    bool fourKind = false;
    bool threeKind = false;
    int pairs = 0;
};

HandStats analyzeHand(const Hand& hand) {
    HandStats stats;
    if (hand.cards.empty() || hand.cards.size() > 5) return stats;

    std::map<int, int> rankCount;
    std::map<char, int> suitCount;
    for (const Card& card : hand.cards) {
        if (card.rank < 2 || card.rank > 14) return stats;
        if (card.suit != 'H' && card.suit != 'D' &&
            card.suit != 'C' && card.suit != 'S') return stats;
        ++rankCount[card.rank];
        ++suitCount[card.suit];
    }

    stats.valid = true;
    stats.flush = hand.cards.size() == 5 && suitCount.size() == 1;
    for (const auto& entry : rankCount) {
        if (entry.second == 5) stats.fiveKind = true;
        if (entry.second == 4) stats.fourKind = true;
        if (entry.second == 3) stats.threeKind = true;
        if (entry.second == 2) ++stats.pairs;
    }

    std::vector<int> ranks;
    for (const auto& entry : rankCount) ranks.push_back(entry.first);
    if (hand.cards.size() == 5 && ranks.size() == 5) {
        stats.straight = true;
        for (std::size_t i = 1; i < ranks.size(); ++i) {
            if (ranks[i] != ranks[i - 1] + 1) {
                stats.straight = false;
                break;
            }
        }
        if (ranks == std::vector<int>{2, 3, 4, 5, 14}) stats.straight = true;
    }

    stats.royal = stats.straight && stats.flush && rankCount.count(10) &&
        rankCount.count(11) && rankCount.count(12) && rankCount.count(13) &&
        rankCount.count(14);
    return stats;
}

class PokerHandChecker {
public:
    virtual ~PokerHandChecker() = default;
    void setNext(PokerHandChecker* next) { nextChecker = next; }
    HandRank check(const HandStats& stats) const {
        if (!stats.valid) return HandRank::None;
        if (matches(stats)) return getRank();
        return nextChecker ? nextChecker->check(stats) : HandRank::None;
    }

protected:
    virtual bool matches(const HandStats& stats) const = 0;
    virtual HandRank getRank() const = 0;
    PokerHandChecker* nextChecker = nullptr;
};

#define DEFINE_CHECKER(ClassName, Condition, RankName) \
    class ClassName : public PokerHandChecker { \
    protected: \
        bool matches(const HandStats& stats) const override { return (Condition); } \
        HandRank getRank() const override { return HandRank::RankName; } \
    };

DEFINE_CHECKER(FlushFiveChecker, stats.fiveKind && stats.flush, FlushFive)
DEFINE_CHECKER(FlushHouseChecker, stats.threeKind && stats.pairs >= 1 && stats.flush, FlushHouse)
DEFINE_CHECKER(FiveOfAKindChecker, stats.fiveKind, FiveOfAKind)
DEFINE_CHECKER(RoyalFlushChecker, stats.royal, RoyalFlush)
DEFINE_CHECKER(StraightFlushChecker, stats.straight && stats.flush, StraightFlush)
DEFINE_CHECKER(FourOfAKindChecker, stats.fourKind, FourOfAKind)
DEFINE_CHECKER(FullHouseChecker, stats.threeKind && stats.pairs >= 1, FullHouse)
DEFINE_CHECKER(FlushChecker, stats.flush, Flush)
DEFINE_CHECKER(StraightChecker, stats.straight, Straight)
DEFINE_CHECKER(ThreeOfAKindChecker, stats.threeKind, ThreeOfAKind)
DEFINE_CHECKER(TwoPairChecker, stats.pairs >= 2, TwoPair)
DEFINE_CHECKER(PairChecker, stats.pairs == 1, Pair)
DEFINE_CHECKER(HighCardChecker, stats.valid, HighCard)

#undef DEFINE_CHECKER
} // namespace

HandRank HandEvaluatorChain::evaluate(const Hand& hand) const {
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveKind);
    fiveKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourKind);
    fourKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeKind);
    threeKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    return flushFive.check(analyzeHand(hand));
}
