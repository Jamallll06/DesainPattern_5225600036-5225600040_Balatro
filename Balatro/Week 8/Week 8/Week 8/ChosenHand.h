#pragma once

#include "Hand.h"
#include <vector>

class ChosenHand {
public:
    static const std::size_t MAX_CARDS = 5;

    bool addCard(const Card& card);
    bool toggleCard(const Card& card);
    void setCards(const std::vector<Card>& cards);
    void clear();
    std::size_t size() const;
    bool isValid() const;
    Hand toHand() const;
    const std::vector<Card>& getCards() const;

private:
    std::vector<Card> selectedCards;
};
