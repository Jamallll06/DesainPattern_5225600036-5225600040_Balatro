#include "HandScoring.h"

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

HandRank ChainScoringRule::evaluateRank(const Hand& hand) const {
    return evaluator.evaluate(hand);
}

int ChainScoringRule::computeBaseScore(const Hand& hand) {
    return handScore(evaluator.evaluate(hand));
}
