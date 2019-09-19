#include "pch.h"
#include "VideoGame.h"
#include <iostream>
using namespace std;

VideoGame::VideoGame() {
	highScore = 0;
}

VideoGame::VideoGame(int oneScore, int twoScore, int scoreHigh = 0) : Games(oneScore, twoScore) {
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
