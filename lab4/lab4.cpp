#include <iostream>
#include <string>
#include "game.h"
#include "BoardGame.h"
#include "VideoGame.h"
using namespace std;


void displayAttributes(Game game) {
    cout << "Player One Score: " << game.getPlayerOneScore() << endl;
	cout << "Player Two Score: " << game.getPlayerTwoScore() << endl;
}

void displayAttributes(BoardGame game) {
    cout << "Player One Score: " << game.getPlayerOneScore() << endl;
	cout << "Player Two Score: " << game.getPlayerTwoScore() << endl;
	cout << "Dice Roll: " << game.getDiceRoll() << endl;
}

void displayAttributes(VideoGame game) {
    cout << "Player One Score: " << game.getPlayerOneScore() << endl;
	cout << "Player Two Score: " << game.getPlayerTwoScore() << endl;
	cout << "Username: " << game.getUsername() << endl;
}

void attributeUpdates(Game *games) {
	int playerOneScore;
	int playerTwoScore;

	displayAttributes(* games);
	cout << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games->setPlayerOneScore(playerOneScore);
	cout << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games->setPlayerTwoScore(playerTwoScore);
}

void attributeUpdates(BoardGame &games) {
	int playerOneScore;
	int playerTwoScore;
	int diceRoll;

    displayAttributes(games);
	cout << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	do {
		cout << "Enter the new Dice Roll (1-6): ";
		cin >> diceRoll;
	} while (diceRoll < 1 || diceRoll > 6);
	games.setDiceRoll(diceRoll);
}

void attributeUpdates(VideoGame &games) {
	int playerOneScore;
	int playerTwoScore;
	string newUsername;

    displayAttributes(games);
	cout << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	cout << "Enter the new username: ";
	cin >> newUsername;
	games.setUsername(newUsername);
}

int main(){
    string userIn2;
    int userIn;
    do{
        cout << "Press 1 for an instance of game." << endl;
        cout << "Press 2 for an instance of board game." << endl;
        cout << "Press 3 for an instance of video game." << endl;
        cout << "Press 4 for an instance of a board game declared as a game." << endl;
        cout << "Press 5 for an instance of a video game declared as a game." << endl;
        cin >> userIn;

        if(userIn == 1){
            Game game;
            game.Play();
            game.Winner();
            attributeUpdates(&game);
        }
        else if(userIn == 2){
            BoardGame game;
            game.Play();
            game.Winner();
            attributeUpdates(game);
        }
        else if(userIn == 3){
            VideoGame game;
            game.Play();
            game.Winner();
            attributeUpdates(game);
        }
        else if(userIn == 4){
            BoardGame bgame;
            Game *baseGame = &bgame;
            baseGame->Play();
            baseGame->Winner();
            attributeUpdates(baseGame);
        }
        else if(userIn == 5){
            VideoGame videoGame;
            Game *baseGame = &videoGame;
            baseGame->Play();
            baseGame->Winner();
            attributeUpdates(baseGame);
        }
        else{
            cout << "Invalid choice." << endl;
        }

        cout << "Would you like to continue? (y/n): ";
        cin >> userIn2;
    }
    while(userIn2 == "y");
}
