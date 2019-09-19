#pragma once
#include "BoardGame.h"
using namespace std;

const int shelfMaxSize = 10;
class Shelf {
private:
    BoardGame* games[shelfMaxSize];
    int currentSize;
public:
    Shelf();
    void add(BoardGame newGame);
    BoardGame remove();
    int getCurrentSize();
};