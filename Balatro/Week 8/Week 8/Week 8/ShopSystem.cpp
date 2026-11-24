#include "ShopSystem.h"
#include <iostream>

void ShopSystem::printOffer(int money) const {
    std::cout << "[SHOP] offered: Bonus(+2) cost 2 (money: "
        << money << ")\n";
    std::cout << "[SHOP] skipped\n";
}
