#include "pch.h"
#include "Shelf.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
#include <iostream>
using namespace std;

void shelfClassTest(Shelf shelf) {
	int input = 0;

	do {
		do {
			cout << "Press 1 to add a board game to the shelf." << endl;
			cout << "Press 2 remove a board game from the shelf." << endl;
			cout << "Press 3 see how many board games are currently on the shelf." << endl;
			cout << "Press 4 to quit." << endl << endl;
			cin >> input;
			cout << endl;
		} while (input < 1 || input > 4);

		if (input == 1) {
			BoardGame *newgame = new BoardGame;
			try
			{
				shelf.addBoardGame(newgame);
			}
			catch (FullShelf e) {
				cout << "Error: The shelf is full." << endl << endl;
			}
		}
		else if (input == 2) {
			try {
				shelf.removeBoardGame();
			}
			catch (EmptyShelf e) {
				cout << "Error: The shelf is empty." << endl << endl;
			}
		}
		else if (input == 3) {
			cout << "Number of board games on shelf: " << shelf.getNumBoardGames() << endl << endl;
		}
	} while (input != 4);
}

int main()
{
	Shelf shelf;

	shelfClassTest(shelf);
}
