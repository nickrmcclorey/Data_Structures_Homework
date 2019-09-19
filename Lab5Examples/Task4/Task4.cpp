#include "pch.h"
#include "EntertainmentCollection.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
#include "BoardGame.h"
#include "VideoGame.h"
#include <iostream>
using namespace std;

template <class T>
void shelfClassTest(EntertainmentCollection<T> newGame, int input);

int main()
{
	int input = 0;

	do {
		cout << "Which type of games do you want for your collection ?(1=Board Game, 2=Video Game)" << endl << endl;
		cin >> input;
		cout << endl;
	} while (input != 1 && input != 2);

	if (input == 1) {
		EntertainmentCollection<BoardGame> boardGame;
		shelfClassTest(boardGame, input);
	}
	else {
		EntertainmentCollection<VideoGame> videoGame;
		shelfClassTest(videoGame, input);
	}
}

template <class T>
void shelfClassTest(EntertainmentCollection<T> newGame, int input) {
	int userinput;

	do {
		if (input == 1) {
			do {
				cout << "Press 1 to add a board game to the collection." << endl;
				cout << "Press 2 remove a board game from the collection." << endl;
				cout << "Press 3 see how many board games are currently in the collection." << endl;
				cout << "Press 4 to quit." << endl << endl;
				cin >> userinput;
				cout << endl;
			} while (userinput < 1 || userinput > 4);

			if (userinput == 1) {
				T newgame;
				try
				{
					newGame.addGame(newgame);
				}
				catch (FullShelf e) {
					cout << "Error: The entertainment collection is full." << endl << endl;
				}
			}
			else if (userinput == 2) {
				T newgame2;
				try {
					newGame.removeBoardGame();
				}
				catch (EmptyShelf e) {
					cout << "Error: The entertainment collection is empty." << endl << endl;
				}
			}
			else if (userinput == 3) {
				cout << "Number of board games in entertainment collection: " << newGame.getNumGames() << endl << endl;
			}
		}

		if (input == 2) {
			do {
				cout << "Press 1 to add a video game to the collection." << endl;
				cout << "Press 2 remove a video game from the collection." << endl;
				cout << "Press 3 see how many video games are currently in the collection." << endl;
				cout << "Press 4 to quit." << endl << endl;
				cin >> userinput;
				cout << endl;
			} while (userinput < 1 || userinput > 4);

			if (userinput == 1) {
				T newgame3;
				try
				{
					newGame.addGame(newgame3);
				}
				catch (FullShelf e) {
					cout << "Error: The entertainment collection is full." << endl << endl;
				}
			}
			else if (userinput == 2) {
				T newgame4;
				try {
					newGame.removeVideoGame();
				}
				catch (EmptyShelf e) {
					cout << "Error: The entertainment collection is empty." << endl << endl;
				}
			}
			else if (userinput == 3) {
				cout << "Number of video games in entertainment collection: " << newGame.getNumGames() << endl << endl;
			}
		}
	} while (userinput != 4);
}