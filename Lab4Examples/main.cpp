#include "pch.h"
#include "Games.h"
#include "BoardGame.h"
#include "VideoGame.h"
#include <iostream>
#include <string>
using namespace std;

void attributeUpdates(Games &);
void attributeUpdates(Games *);
void attributeUpdates(BoardGame &);
void attributeUpdates(VideoGame &);

void classCreation(int &option, int &playerOneScore, int &playerTwoScore){
	do {
		cout << "Enter which class to create: " << endl << endl;
		cout << "Press 1 for an instance of game." << endl;
		cout << "Press 2 for an instance of board game." << endl;
		cout << "Press 3 for an instance of video game." << endl;
		cout << "Press 4 for an instance of a board game declared as a game" << endl;
		cout << "Press 5 for an instance of a video game declared as a game" << endl << endl;
		cin >> option;
		cout << endl;
	} while (option < 1 || option > 5);

	cout << "Enter the Player One score: ";
	cin >> playerOneScore;

	cout << endl << "Enter the Player Two score: ";
	cin >> playerTwoScore;
}

void instanceCreator(int &option, int &playerOneScore, int &playerTwoScore){
	int rollDice = 0;
	int highScore = 0;

	if (option == 1) {
		Games game2(playerOneScore, playerTwoScore);
		game2.Play();
		game2.Winner();
		attributeUpdates(game2);
	}
	else if (option == 2) {
		do {
			cout << endl << "Enter the dice roll number (1-6): ";
			cin >> rollDice;
		} while (rollDice < 1 || rollDice > 6);

		BoardGame boardgame2(playerOneScore, playerTwoScore, rollDice);
		boardgame2.Play();
		boardgame2.Winner();
		attributeUpdates(boardgame2);
	}
	else if (option == 3) {
		cout << endl << "Enter the high score #: ";
		cin >> highScore;

		VideoGame videogame2(playerOneScore, playerTwoScore, highScore);
		videogame2.Play();
		videogame2.Winner();
		attributeUpdates(videogame2);
	}
	else if (option == 4) {
		Games *game3 = new BoardGame(playerOneScore, playerTwoScore, rollDice);
		game3->Play();
		game3->Winner();
		attributeUpdates(game3);
		delete game3;
	}
	else {
		Games *game4 = new VideoGame(playerOneScore, playerTwoScore, highScore);
		game4->Play();
		game4->Winner();
		attributeUpdates(game4);
		delete game4;
	}
}

int main()
{
	int option = 0;
	int playerOneScore = 0;
	int playerTwoScore = 0;
	string answer;
	Games game1;
	BoardGame boardgame1;
	VideoGame videogame1;

	do {
		classCreation(option, playerOneScore, playerTwoScore);

		instanceCreator(option, playerOneScore, playerTwoScore);

		do {
			cout << endl << "Would you like to continue? Enter 'yes' or 'no': ";
			cin >> answer;
			cout << endl;
		} while (answer != "yes" && answer != "no");
	} while (answer == "yes");
}

void attributeUpdates(Games &games) {
	int playerOneScore;
	int playerTwoScore;

	cout << endl << "Player One Score: " << games.getPlayerOneScore() << endl;
	cout << endl << "Player Two Score: " << games.getPlayerTwoScore() << endl;
	cout << endl << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << endl << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
}

void attributeUpdates(Games *games) {
	int playerOneScore;
	int playerTwoScore;

	cout << endl << "Player One Score: " << games->getPlayerOneScore() << endl;
	cout << endl << "Player Two Score: " << games->getPlayerTwoScore() << endl;
	cout << endl << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games->setPlayerOneScore(playerOneScore);
	cout << endl << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games->setPlayerTwoScore(playerTwoScore);
}

void attributeUpdates(BoardGame &games) {
	int playerOneScore;
	int playerTwoScore;
	int diceRoll;

	cout << endl << "Player One Score: " << games.getPlayerOneScore() << endl;
	cout << endl << "Player Two Score: " << games.getPlayerTwoScore() << endl;
	cout << endl << "Dice Roll: " << games.getDiceRoll() << endl;
	cout << endl << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << endl << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	do {
		cout << endl << "Enter the new Dice Roll (1-6): ";
		cin >> diceRoll;
	} while (diceRoll < 1 || diceRoll > 6);
	games.setDiceRoll(diceRoll);
}

void attributeUpdates(VideoGame &games) {
	int playerOneScore;
	int playerTwoScore;
	int highScore;

	cout << endl << "Player One Score: " << games.getPlayerOneScore() << endl;
	cout << endl << "Player Two Score: " << games.getPlayerTwoScore() << endl;
	cout << endl << "High Score: " << games.getHighScore() << endl;
	cout << endl << "Enter the new Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << endl << "Enter the new Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	cout << endl << "Enter the new High Score: ";
	cin >> highScore;
	games.setHighScore(highScore);
}
