#include <iostream>
#include "game.h"
#include "BoardGame.h"

using namespace std;

void BoardGame::setDiceRoll(int dice){
    diceRoll = dice;
}

int BoardGame::getDiceRoll(){
    return diceRoll;
}

void BoardGame::Play(){
    cout << "Roll the dice." << endl;
}

void BoardGame::Winner(){
    cout << "Dancing time!" << endl;
}
        