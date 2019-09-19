#include <iostream>
#include <string>
#include "EntertainmentCollection.h"
#include "game.h"
#include "BoardGame.h"
#include "VideoGame.h"
#include "FullCollection.h"
#include "EmptyCollection.h"
using namespace std;

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

void attributeUpdates(VideoGame &games) {
	int playerOneScore;
	int playerTwoScore;
	string newUsername;

	cout << "Enter the Player One Score: ";
	cin >> playerOneScore;
	games.setPlayerOneScore(playerOneScore);
	cout << "Enter the Player Two Score: ";
	cin >> playerTwoScore;
	games.setPlayerTwoScore(playerTwoScore);
	cout << "Enter the username: ";
	cin >> newUsername;
	games.setUsername(newUsername);
}

template <class T>
void modifyEntertainmentCollection(EntertainmentCollection<T> s1){ 
    string userIn2;
    do{
        cout << "Press 1 to add a game to the collection." << endl; //Might need to add cases to say "video/board game" instead of just "game"
        cout << "Press 2 to remove a game from the collection." << endl;
        cout << "Press 3 to see how many games are on the collection." << endl;
        cout << "Press 4 to quit." << endl;
        cin >> userIn2;
        if(userIn2 == "1"){
            T game1;
            attributeUpdates(game1);
            try{
                s1.add(game1);
            }
            catch(FullCollection full){
                cout << "Can't add game to full collection." << endl;
                continue;
            }
        }
        else if(userIn2 == "2"){
            T game2;
            try{
                game2 = s1.remove();
            }
            catch(EmptyCollection exception){
                cout << "Can't remove game from empty collection." << endl;
                continue;
            }
            displayAttributes(game2);
        }
        else if(userIn2 == "3"){
            cout << "Games in collection currently: " << s1.getCurrentSize() << endl;
        }
        else if(userIn2 == "4"){
            cout << "Quiting." << endl;
        }
        else{
            cout << "Please enter a valid choice." << endl;
        }
    }
    while(userIn2 != "4");
}

int main(){
    string userIn1;
    
    do{
        cout << "Which game type should your collection hold? (1 = Board Game, 2 = Video Game)" << endl;
        cin >> userIn1;
        if(userIn1 == "1"){
            EntertainmentCollection<BoardGame> collection1;
            modifyEntertainmentCollection(collection1);
        }
        else if(userIn1 == "2"){
            EntertainmentCollection<VideoGame> collection1;
            modifyEntertainmentCollection(collection1);
        }
        else{
            cout << "Invalid entry." << endl;
        }
    }
    while(userIn1 != "1" && userIn1 != "2");
    
    return 0;
}