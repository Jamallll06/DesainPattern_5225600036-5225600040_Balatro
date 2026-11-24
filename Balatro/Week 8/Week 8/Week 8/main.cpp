#include "CheckerDemo.h"
#include "HandGenerator.h"
#include "HandScoring.h"
#include "RewardRule.h"
#include "RunSession.h"
#include <memory>

int main() {
    runCheckerDemo();

    RunSession game(
        std::make_unique<RandomHandGenerator>(),
        std::make_unique<ChainScoringRule>(),
        std::make_unique<DynamicRewardRule>());
    game.startRun();
    return 0;
}
