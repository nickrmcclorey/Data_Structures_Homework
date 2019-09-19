#include <iostream>
#include <string>
#include "Shelf.h"
#include "game.h"
#include "BoardGame.h"
#include "FullShelf.h"
#include "EmptyShelf.h"
using namespace std;

void displayAttributes(BoardGame game) {
    cout << "Player One Score: " << game.getPlayerOneScore() << endl;
	cout << "Player Two Score: " << game.getPlayerTwoScore() << endl;
	cout << "Dice Roll: " << game.getDiceRoll() << endl;
}

void attributeUpdates(BoardGame &games) {
	int playerOneScore;
	int playerTwoScore;
	int diceRoll;

	cout << "Enter the Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << "Enter the Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	do {
		cout << "Enter the Dice Roll (1-6): ";
		cin >> diceRoll;
	} while (diceRoll < 1 || diceRoll > 6);
	games.setDiceRoll(diceRoll);
}

int main(){
    string userIn;
    Shelf shelf1;
    
    do{
        cout << "Press 1 to add a board game to the shelf." << endl;
        cout << "Press 2 to remove a board game from the shelf." << endl;
        cout << "Press 3 to see how many board games are on the shelf." << endl;
        cout << "Press 4 to quit." << endl;
        cin >> userIn;
        if(userIn == "1"){
            //add a board game
            BoardGame game1;
            attributeUpdates(game1);
            try{
                shelf1.add(game1);
            }
            catch(FullShelf full){
                //Error handling
                cout << "Can't add game to full shelf." << endl;
            }
        }
        else if(userIn == "2"){
            //remove a board game, show attributes with displayAttributes function
            BoardGame game2;
            try{
                game2 = shelf1.remove();
            }
            catch(EmptyShelf exception){
                //Error handling
                cout << "Can't remove game from empty shelf." << endl;
            }
            displayAttributes(game2);
        }
        else if(userIn == "3"){
            //return boardGameCount variable
            cout << "Games on shelf currently: " << shelf1.getCurrentSize() << endl;
        }
        else if(userIn == "4"){
            cout << "Quiting." << endl;
        }
        else{
            cout << "Please enter a valid choice." << endl;
        }
    }
    while(userIn != "4");
    
    return 0;
}