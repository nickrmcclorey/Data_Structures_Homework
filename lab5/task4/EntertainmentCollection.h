#pragma once
#include "BoardGame.h"
#include "FullCollection.h"
#include "EmptyCollection.h"
using namespace std;

const int shelfMaxSize = 10;

template <class T>
class EntertainmentCollection {
private:
    T games[shelfMaxSize];
    int currentSize;
public:
    EntertainmentCollection();
    void add(T newGame);
    T remove();
    int getCurrentSize();
};


template <class T>
EntertainmentCollection<T>::EntertainmentCollection() {
    currentSize = 0;
}

template <class T>
void EntertainmentCollection<T>::add(T newGame) {
    if (currentSize >= shelfMaxSize) {
        FullCollection exception;
        exception.errorMessage = "Max shelf size is 10";    
        throw exception;
    }
    games[currentSize] = newGame;
    currentSize++;
}

template <class T>
T EntertainmentCollection<T>::remove() {
    if (currentSize <= 0) {
        EmptyCollection exception;
        exception.errorMessage = "Shelf is empty.";
        throw exception;
    }
    
    T toReturn =  games[currentSize - 1];
    currentSize--;

    return toReturn;
}

template <class T>
int EntertainmentCollection<T>::getCurrentSize() {
    return currentSize;
}