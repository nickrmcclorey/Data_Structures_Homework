#include "Shelf.h"
#include "FullShelf.h"
#include "EmptyShelf.h"

Shelf::Shelf() {
    for (int k = 0; k < shelfMaxSize; k++) {
        games[k] = nullptr;
    }
    currentSize = 0;
}

void Shelf::add(BoardGame newGame) {
    if (currentSize >= shelfMaxSize) {
        FullShelf exception;
        exception.errorMessage = "Max shelf size is 10";    
        throw exception;
    }
    games[currentSize] = &newGame;
    currentSize++;
}

BoardGame Shelf::remove() {
    if (currentSize <= 0) {
        EmptyShelf exception;
        exception.errorMessage = "Shelf is empty.";
        throw exception;
    }
    BoardGame toReturn =  *games[currentSize - 1];

    games[currentSize - 1] = nullptr;
    currentSize--;

    return toReturn;
}

int Shelf::getCurrentSize() {
    return currentSize;
}