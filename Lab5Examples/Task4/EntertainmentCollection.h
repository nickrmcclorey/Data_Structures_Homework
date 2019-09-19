#pragma once
#include "BoardGame.h"
#include "VideoGame.h"

const int entertainmentCollectionSize = 10;

template <class T>
class EntertainmentCollection {
private:
	T games[entertainmentCollectionSize];
	int numGames;
public:
	EntertainmentCollection();
	void addGame(T);
	T removeBoardGame();
	T removeVideoGame();
	int getNumGames();
};
