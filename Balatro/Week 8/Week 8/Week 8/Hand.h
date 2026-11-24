#pragma once

#include "Card.h"
#include <initializer_list>
#include <string>
#include <vector>

struct Hand {
    std::vector<Card> cards;

    Hand() = default;
    Hand(std::initializer_list<Card> input) : cards(input) {}
};

std::string handString(const Hand& hand);
