#pragma once

class Game {
private:
	int playerOneScore;
	int playerTwoScore;
public:
	virtual void Play();
	void Winner();
	void setPlayerOneScore(int oneScore);
	void setPlayerTwoScore(int twoScore);
	int getPlayerOneScore();
	int getPlayerTwoScore();
	Game();
	Game(int oneScore, int twoScore);
};
