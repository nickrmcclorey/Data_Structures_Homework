#include "pch.h"
#include "BoardGame.h"
#include <iostream>
using namespace std;


BoardGame::BoardGame(){
	playerOneScore = 5;
	playerTwoScore = 15;
	diceRoll = 4;
}

BoardGame::BoardGame(int oneScore, int twoScore, int rollDice){
	playerOneScore = oneScore;
	playerTwoScore = twoScore;
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


void BoardGame::setPlayerOneScore(int oneScore){
	playerOneScore = oneScore;
}

void BoardGame::setPlayerTwoScore(int twoScore) {
	playerTwoScore = twoScore;
}

int BoardGame::getDiceRoll() {
	return diceRoll;
}

int BoardGame::getPlayerOneScore() {
	return playerOneScore;
}

int BoardGame::getPlayerTwoScore() {
	return playerTwoScore;
}
