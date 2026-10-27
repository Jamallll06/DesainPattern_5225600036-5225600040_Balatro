#pragma once
#include "Hand.h"

class ChosenHand {
private:
    Hand selectedHand;
    int maxCards;

public:
    explicit ChosenHand(int max = 5);

    bool addCard(const Card& card);
    bool removeCard(int index);
    void clearHand();

    Hand getHand() const;
    int getCardCount() const;
    bool isEmpty() const;
    bool isFull() const;
};
