#include "ChosenHand.h"
#include <algorithm>

ChosenHand::ChosenHand(int max) : maxCards(max > 0 ? max : 5) {}

bool ChosenHand::addCard(const Card& card) {
    if (isFull()) return false;
    selectedHand.cards.push_back(card);
    return true;
}

bool ChosenHand::removeCard(int index) {
    if (index < 0 || index >= getCardCount()) return false;
    selectedHand.cards.erase(selectedHand.cards.begin() + index);
    return true;
}

void ChosenHand::clearHand() {
    selectedHand.cards.clear();
}

Hand ChosenHand::getHand() const {
    return selectedHand;
}

int ChosenHand::getCardCount() const {
    return static_cast<int>(selectedHand.cards.size());
}

bool ChosenHand::isEmpty() const {
    return selectedHand.cards.empty();
}

bool ChosenHand::isFull() const {
    return getCardCount() >= maxCards;
}
