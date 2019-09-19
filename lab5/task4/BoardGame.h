#pragma once
#include "game.h"

class BoardGame: public Game {
    private:
        int diceRoll;
    public:
        void setDiceRoll(int dice);
        int getDiceRoll();
        void Play();
        void Winner();
};