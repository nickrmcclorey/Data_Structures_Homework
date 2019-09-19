#include "pch.h"
#include "Games.h"
#include <iostream>
using namespace std;

void Games::setPlayerOneScore(int oneScore) {
	playerOneScore = oneScore;
}

void Games::setPlayerTwoScore(int twoScore) {
	playerTwoScore = twoScore;
}

int Games::getPlayerOneScore(){
	return playerOneScore;
}

int Games::getPlayerTwoScore() {
	return playerTwoScore;
}

Games::Games() {
	playerOneScore = 0;
	playerTwoScore = 0;
}

Games::Games(int oneScore, int twoScore) {
	playerOneScore = oneScore;
	playerTwoScore = twoScore;
}

void Games::Play() {
	return;
}

void Games::Winner() {
	cout << endl << "Not Yet" << endl;
}
