#pragma once

class Games {
private:
	int playerOneScore;
	int playerTwoScore;
public:
	void setPlayerOneScore(int);
	void setPlayerTwoScore(int);
	int getPlayerOneScore();
	int getPlayerTwoScore();
	Games();
	Games(int, int);
	virtual void Play();
	void Winner();
};
