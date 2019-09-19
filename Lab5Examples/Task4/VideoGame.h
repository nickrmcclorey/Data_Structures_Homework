#pragma once

class VideoGame {
private:
	int playerOneScore;
	int playerTwoScore;
	int highScore;
public:
	VideoGame();
	VideoGame(int, int, int);
	void Play();
	void Winner();
	void setHighScore(int);
	int getHighScore();
};