#include <iostream>
#include "game.h"
using namespace std;

Game::Game() {
	playerOneScore = 0;
	playerTwoScore = 0;
}

Game::Game(int oneScore, int twoScore) {
	playerOneScore = oneScore;
	playerTwoScore = twoScore;
}

void Game::Winner() {
	cout << "Not Yet" << endl;
}

void Game::Play(){
    cout << "game playing" << endl;
}
	
void Game::setPlayerOneScore(int oneScore) {
	playerOneScore = oneScore;
}

void Game::setPlayerTwoScore(int twoScore) {
	playerTwoScore = twoScore;
}

int Game::getPlayerOneScore() {
	return playerOneScore;
}

int Game::getPlayerTwoScore() {
	return playerTwoScore;
}
