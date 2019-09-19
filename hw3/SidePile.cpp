#include "SidePile.h"

SidePile::SidePile() {
    for (int k = 0; k < 5; k++) {
        pile[k] = 0;
    }
}

int SidePile::CardsInPile(){
    int counter = 0;
    for(int i = 0; i < 5; i++){
        if(pile[i] != 0){
            counter += 1;
        }
    }
    return counter;
}

void SidePile::AddToPile(int i){
    if(CardsInPile() == 5){
        //throw error
    }
    int counter = 0;
    while(pile[counter] != 0){
        counter += 1;
    }
    pile[counter] = i;
}

int SidePile::TakeFromPile(){
    if(CardsInPile() == 0){
        //throw error
    }
    int counter = 4, temp;
    while(pile[counter] == 0){
        counter -= 1;
    }
    temp = pile[counter];
    pile[counter] = 0;
    return temp;
}