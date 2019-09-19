#pragma once
#include "Games.h"

class VideoGame : public Games{
private:
	int playerOneScore;
	int playerTwoScore;
	int highScore;
public:
	VideoGame();
	VideoGame(int, int, int);
	virtual void Play();
	void Winner();
	void setHighScore(int);
	int getHighScore();
};
