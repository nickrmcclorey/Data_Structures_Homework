#include <iostream>
#include <string>
#include "input.h"
#include "Player.h"
#include "Wheel.h"
using namespace std;

int wagerIncrease(Player player) {

    if (!askYesOrNo("Do you want to increase your wager?\n")) {
        return 0;
    }

    int answer = -1;
    while (answer < 0 || answer > player.betAmount * 2 || answer + player.betAmount > player.money) {
        
        answer = askInt("How much do you want to increase your wager?\n");

        if (answer < 0) {
            cout << "You cannot decrease your wager." << endl;
        } else if (answer > player.betAmount * 2) {
            cout << "You cannot increase your bet by more than double the original wager." << endl;
        } else if (answer + player.betAmount > player.money) {
            cout << "You cannot bet more money than you have" << endl;
        }
    }

    return answer;
}

int getOriginalBet(Player player) {
    int betAmount = -1;
    while (betAmount > player.money || betAmount < 0) {

        betAmount = askInt("How much do you want to bet\n");
        if (betAmount > player.money) {
            cout << "you don't have enough money to bet that much." << endl;
        } else if (betAmount < 0) {
            cout << "you can't bet a negative amount of money." << endl;
        }
    }
    return betAmount;
}

int wheelRange() {
    int answer = -1;
    while (answer < 6 || answer > 20) {
        answer = askInt("How many values do you want on the wheel?\n");

        if (answer < 6 || answer > 20) {
            cout << "The wheel has a minimum of six values and a maximum of 20" << endl;
        }
    }
    return answer;
}

int main() {

    int numVals = wheelRange();
    Player player;
    Wheel houseWheel(1, numVals);
    player.money = 100;
    bool playerWantsToKeepPlaying = true;

    cout << "You have $" << player.money << endl;
    while (player.money > 0 && playerWantsToKeepPlaying) {
        player.betAmount = getOriginalBet(player);
        player.rollResult = player.wheel.spin();

        cout << "You rolled a " << player.rollResult << "." << endl;
        player.betAmount += wagerIncrease(player);
        int houseResult = houseWheel.spin();
        cout << "The house rolled a " << houseResult << "." << endl;

        if (houseResult >= player.rollResult) {
            cout << "You lost $" << player.betAmount << "." << endl;
            player.money -= player.betAmount;
        } else {
            cout << "You won $" << player.betAmount << "." << endl;
            player.money += player.betAmount;
        }
        player.betAmount = 0;

        cout << "You have $" << player.money << endl;
        if (player.money > 0) {
            playerWantsToKeepPlaying = askYesOrNo("Do you want to keep playing?\n");
        }
    }

    return 0;
}