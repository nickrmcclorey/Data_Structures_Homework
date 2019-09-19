#include <string>
#include <iostream>
#include "game.h"
#include "VideoGame.h"

using namespace std;

void VideoGame::Winner() {
    cout << "Winner, winner, chicken dinner!" << endl;
}

void VideoGame::Play() {
    cout << "Mash the buttons" << endl;
}

void VideoGame::setUsername(string input) {
    username = input;
}

string VideoGame::getUsername() {
    return username;
}