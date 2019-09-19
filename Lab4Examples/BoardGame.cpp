#include "pch.h"
#include "BoardGame.h"
#include "Games.h"
#include <iostream>
using namespace std;


BoardGame::BoardGame() : Games() {
	diceRoll = 0;
}

BoardGame::BoardGame(int oneScore, int twoScore, int rollDice = 0) : Games(oneScore, twoScore) {
	diceRoll = rollDice;
}

void BoardGame::Play() {
	cout << endl << "Roll the dice." << endl;
}

void BoardGame::Winner() {
	cout << endl << "Dancing time." << endl;
}

void BoardGame::setDiceRoll(int rollDice) {
	diceRoll = rollDice;
}

int BoardGame::getDiceRoll() {
	return diceRoll;
}
