#include "CheckerDemo.h"
#include "HandEvaluator.h"
#include "HandScoring.h"
#include <iostream>
#include <vector>

void runCheckerDemo() {
    const HandEvaluatorChain evaluator;
    struct TestCase {
        Hand hand;
        HandRank expected;
    };

    const std::vector<TestCase> cases = {
        {{ {2,'H'}, {5,'D'}, {9,'C'}, {11,'S'}, {13,'H'} }, HandRank::HighCard},
        {{ {5,'H'}, {5,'D'}, {9,'C'}, {11,'S'}, {13,'H'} }, HandRank::Pair},
        {{ {5,'H'}, {5,'D'}, {9,'C'}, {9,'S'}, {13,'H'} }, HandRank::TwoPair},
        {{ {5,'H'}, {5,'D'}, {5,'C'}, {11,'S'}, {13,'H'} }, HandRank::ThreeOfAKind},
        {{ {5,'H'}, {6,'D'}, {7,'C'}, {8,'S'}, {9,'H'} }, HandRank::Straight},
        {{ {2,'H'}, {5,'H'}, {9,'H'}, {11,'H'}, {13,'H'} }, HandRank::Flush},
        {{ {5,'H'}, {5,'D'}, {5,'C'}, {9,'S'}, {9,'H'} }, HandRank::FullHouse},
        {{ {5,'H'}, {5,'D'}, {5,'C'}, {5,'S'}, {13,'H'} }, HandRank::FourOfAKind},
        {{ {5,'H'}, {6,'H'}, {7,'H'}, {8,'H'}, {9,'H'} }, HandRank::StraightFlush},
        {{ {10,'S'}, {11,'S'}, {12,'S'}, {13,'S'}, {14,'S'} }, HandRank::RoyalFlush},
        {{ {5,'H'}, {5,'D'}, {5,'C'}, {5,'S'}, {5,'H'} }, HandRank::FiveOfAKind},
        {{ {5,'H'}, {5,'H'}, {5,'H'}, {9,'H'}, {9,'H'} }, HandRank::FlushHouse},
        {{ {5,'H'}, {5,'H'}, {5,'H'}, {5,'H'}, {5,'H'} }, HandRank::FlushFive}
    };

    std::cout << "=== CHAIN CHECKER DEMO ===\n";
    for (const TestCase& test : cases) {
        const HandRank result = evaluator.evaluate(test.hand);
        std::cout << "[" << (result == test.expected ? "PASS" : "FAIL") << "] "
            << handString(test.hand) << " -> " << handRankName(result)
            << " (score " << handScore(result) << ")\n";
    }
}
