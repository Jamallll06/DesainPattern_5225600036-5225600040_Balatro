#include "JokerCard.h"
#include <iostream>

JokerCard::JokerCard(int scoreBonus)
    : bonus(scoreBonus >= 0 ? scoreBonus : 0) {}

void JokerCard::onHandPlayed(int score) const {
    std::cout << "Joker menerima notifikasi: hand dimainkan dengan skor "
              << score << ".\n";
}

int JokerCard::modifyScore(int score) const {
    return score + bonus;
}
