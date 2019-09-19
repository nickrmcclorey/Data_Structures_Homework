#pragma once
#include "Games.h"

class BoardGame : public Games {
private:
	int playerOneScore;
	int playerTwoScore;
	int diceRoll;
public:
	BoardGame();
	BoardGame(int, int, int);
	virtual void Play();
	void Winner();
	void setDiceRoll(int);
	int getDiceRoll();

};
