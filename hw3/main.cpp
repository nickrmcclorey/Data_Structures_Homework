#include <iostream>
#include <vector>
#include <algorithm>
#include "Deck.h"
#include "SidePile.h"
using namespace std;

Deck* randomDecks() {
    vector<int> allCards;
    for (int k = 1; k <= 13; k++) {
        allCards.push_back(k);
        allCards.push_back(k);
        allCards.push_back(k);
        allCards.push_back(k);
    }
    random_shuffle(allCards.begin(), allCards.end());

    Deck* decks = new Deck[2];
    for (int k = 0; k < 26; k++) {
        decks[0].AddCards(allCards[k]);
    }
    for (int k = 26; k < 52; k++) {
        decks[1].AddCards(allCards[k]);
    }

    return decks;
}

int askMove(Deck player) {
    int userInput = 0;
    while (userInput < 1 || userInput > 3) {
        cout << "You draw a " << player.Peek() <<". What would you like to do?" << endl;
        cout << "[1] Play this card" << endl;
        cout << "[2] Play this card with a card from the side pile" << endl;
        cout << "[3] Push this card to the side and play the next card in the deck" << endl;
        cin >> userInput;
        if (userInput == 2 && player.sidePileIsEmpty()) {
            cout << "The side pile is empty. Choose another option" << endl;
            userInput = 0;
        } else if (userInput == 3 && player.sidePileIsFull()) {
            cout << "The side pile is full. Choose another option" << endl;
            userInput = 0;
        } else {
            return userInput;
        }
    }
}

int computerDecision(Deck computer) {
    return 1;
}

vector<int> playCards(Deck* player, int decision) {
    vector<int> cardsToPlay;
    if (decision == 1) {
        cardsToPlay.push_back(player->PlayCard());
    } else if (decision == 2) {
        cardsToPlay.push_back(player->PlaySide());
        cardsToPlay.push_back(player->PlayCard());
    } else {
        player->MoveCardToSide();
        cardsToPlay.push_back(player->PlayCard());
    }
    return cardsToPlay;
}

int sum(vector<int> list) {
    int toReturn = 0;
    for (int k = 0; k < list.size(); k++) {
        toReturn += list[k];
    }
    return toReturn;
}

void printPlayedCards(vector<int> playerCards, vector<int> computerCards) {
    cout << "you played: " << playerCards[0];
    if (playerCards.size() > 1) {
        cout << " and " << playerCards[1];
    }
    cout << endl;
    cout << "computer played: " << computerCards[0];
    if (computerCards.size() > 1) {
        cout << " and " << computerCards[1];
    }
    cout << endl << endl;
}

void showDeckCounts(Deck player){
    cout << "Cards in your deck: " << player.CountCards() << endl;
    cout << "Cards in opponent's deck: " << 52 - player.CountCards() << endl << endl;
}

void playWar() {
    Deck* twoDecks = randomDecks();
    Deck player = twoDecks[0];
    Deck computer = twoDecks[1];
    delete [] twoDecks;

    while (computer.CountCards() > 0 && player.CountCards() > 0) {
        // get decisions
        int playerdecision = askMove(player);
        int computersDecision = computerDecision(computer);
        
        // get the cards each player is playing
        vector<int> playerCards = playCards(&player, playerdecision);
        vector<int> computerCards = playCards(&computer, computersDecision);
        printPlayedCards(playerCards, computerCards);

        // compare results and determine winner
        Deck* winner = nullptr;
        if (sum(playerCards) > sum(computerCards)) {
            cout << "You won this round." << endl;
            winner = &player;
        } else {
            cout << "You lost this round." << endl;
            winner = &computer;
        }

        // give winner all the cards
        for (int card : playerCards) {
            winner->AddCards(card);
        }
        for (int card : computerCards) {
            winner->AddCards(card);
        }
        
        // show number of cards in each deck
        showDeckCounts(player);
    }
}

int main() {
    playWar();
    return 0;
}