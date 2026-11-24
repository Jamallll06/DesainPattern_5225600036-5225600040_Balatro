#include "ChosenHand.h"
#include <algorithm>

const std::size_t ChosenHand::MAX_CARDS;

bool ChosenHand::addCard(const Card& card) {
    if (selectedCards.size() >= MAX_CARDS) return false;
    selectedCards.push_back(card);
    return true;
}

bool ChosenHand::toggleCard(const Card& card) {
    auto selected = std::find(selectedCards.begin(), selectedCards.end(), card);
    if (selected != selectedCards.end()) {
        selectedCards.erase(selected);
        return true;
    }
    return addCard(card);
}

void ChosenHand::setCards(const std::vector<Card>& cards) {
    selectedCards.assign(cards.begin(), cards.begin() +
        std::min(cards.size(), MAX_CARDS));
}

void ChosenHand::clear() {
    selectedCards.clear();
}

std::size_t ChosenHand::size() const {
    return selectedCards.size();
}

bool ChosenHand::isValid() const {
    return !selectedCards.empty() && selectedCards.size() <= MAX_CARDS;
}

Hand ChosenHand::toHand() const {
    Hand hand;
    hand.cards = selectedCards;
    return hand;
}

const std::vector<Card>& ChosenHand::getCards() const {
    return selectedCards;
}
