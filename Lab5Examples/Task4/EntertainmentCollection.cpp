#include "pch.h"
#include "EntertainmentCollection.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
#include <iostream>
using namespace std;

template <class T>
EntertainmentCollection<T>::EntertainmentCollection() {
	numGames = 0;
}

template <class T>
void EntertainmentCollection<T>::addGame(T newGame) {
	if (numGames < 10) {
		games[numGames] = newGame;
		numGames++;
	}
	else {
		throw FullShelf::FullShelf();
	}
}

template <class T>
T EntertainmentCollection<T>::removeBoardGame() {
	if (numGames > 0) {
		T removeGame = games[numGames - 1];
		numGames--;
		games[numGames] = nullptr;
		cout << "Player One Score: " << removeGame.getPlayerOneScore() << endl;
		cout << "Player Two Score: " << removeGame.getPlayerTwoScore() << endl;
		cout << "Dice Roll: " << removeGame.getDiceRoll() << endl << endl;
		return removeGame;
	}
	else {
		throw EmptyShelf::EmptyShelf();
	}
}

template <class T>
T EntertainmentCollection<T>::removeVideoGame() {
	if (numGames > 0) {
		T removeGame = games[numGames - 1];
		numGames--;
	
		cout << "Player One Score: " << removeGame.getPlayerOneScore() << endl;
		cout << "Player Two Score: " << removeGame.getPlayerTwoScore() << endl;
		cout << "Dice Roll: " << removeGame.getHighScore() << endl << endl;
		return removeGame;
	}
	else {
		throw EmptyShelf::EmptyShelf();
	}
}

template <class T>
int EntertainmentCollection<T>::getNumGames() {
	return numGames;
}
