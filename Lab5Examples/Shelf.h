#pragma once
#include "BoardGame.h"

const int shelfSize = 10;

class Shelf {
private:
	BoardGame *games[shelfSize];
	int numBoardGames;
public:
	Shelf();
	void addBoardGame(BoardGame *);
	BoardGame removeBoardGame();
	int getNumBoardGames();
};
