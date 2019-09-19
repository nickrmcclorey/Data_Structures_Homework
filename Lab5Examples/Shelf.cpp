#include "pch.h"
#include "Shelf.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
#include <iostream>
using namespace std;

Shelf::Shelf() {
	numBoardGames = 0;
}

void Shelf::addBoardGame(BoardGame *newGame) {
	if (numBoardGames < 10) {
		games[numBoardGames] = newGame;
		numBoardGames++;
	}
	else {
		throw FullShelf::FullShelf();
	}
}

BoardGame Shelf::removeBoardGame() {
	if (numBoardGames > 0) {
		BoardGame removeGame = *games[numBoardGames - 1];
		numBoardGames--;
		games[numBoardGames] = nullptr;
		cout << "Player One Score: " << removeGame.getPlayerOneScore() << endl;
		cout << "Player Two Score: " << removeGame.getPlayerTwoScore() << endl;
		cout << "Dice Roll: " << removeGame.getDiceRoll() << endl << endl;
		return removeGame;
	}
	else {
		throw EmptyShelf::EmptyShelf();
	}
}

int Shelf::getNumBoardGames() {
	return numBoardGames;
}
