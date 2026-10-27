#pragma once

class JokerCard {
private:
    int bonus;

public:
    explicit JokerCard(int scoreBonus = 10);

    void onHandPlayed(int score) const;
    int modifyScore(int score) const;
};
