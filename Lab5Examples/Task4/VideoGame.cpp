#include "pch.h"
#include "VideoGame.h"
#include <iostream>
using namespace std;

VideoGame::VideoGame() {
	playerOneScore = 25;
	playerTwoScore = 50;
	highScore = 85;
}

VideoGame::VideoGame(int oneScore, int twoScore, int scoreHigh) {
	playerOneScore = oneScore;
	playerTwoScore = twoScore;
	highScore = scoreHigh;
}

void VideoGame::Play() {
	cout << endl << "Mash the buttons." << endl;
}

void VideoGame::Winner() {
	cout << endl << "Winner, winner, chicken dinner!" << endl;
}

void VideoGame::setHighScore(int scoreHigh) {
	highScore = scoreHigh;
}

int VideoGame::getHighScore() {
	return highScore;
}
