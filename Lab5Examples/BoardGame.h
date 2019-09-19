#pragma once

class BoardGame {
private:
	int playerOneScore;
	int playerTwoScore;
	int diceRoll;
public:
	BoardGame();
	BoardGame(int, int, int);
	void Play();
	void Winner();
	void setDiceRoll(int);
	int getDiceRoll();
	void setPlayerOneScore(int);
	int getPlayerOneScore();
	void setPlayerTwoScore(int);
	int getPlayerTwoScore();
};
