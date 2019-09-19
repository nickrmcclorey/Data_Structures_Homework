#pragma once
#include "Node.h"
#include "SidePile.h"

class Deck {
    private:
        Node* top;
        SidePile pile;
    public:
        int PlayCard();
        void AddCards(int c1);
        int CountCards();
        void MoveCardToSide();
        int PlaySide();
        int Peek();
        bool sidePileIsEmpty();
        bool sidePileIsFull();
        Deck();
};