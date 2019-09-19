#include "Deck.h"
#include "Node.h"

Deck::Deck(){
    top = nullptr;
}

int Deck::PlayCard(){
    int temp = top->data;
    Node* toDelete = top;
    top = top->next;
    delete toDelete;
    return temp;
}

void Deck::AddCards(int c1){
    if (top == nullptr) {
        top = new Node(c1);
        return;
    }

    Node* temp = top;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(c1);
}

int Deck::CountCards(){
    int counter = 0;
    Node* temp = top;
    while(temp != nullptr){
        temp = temp->next;
        counter++;
    }
    return counter;
}

void Deck::MoveCardToSide(){
    if(pile.CardsInPile() == 5){
        //throw error
    }
    pile.AddToPile(PlayCard());
}

int Deck::Peek(){
    int temp = top->data;
    return temp;
}

int Deck::PlaySide(){
    return pile.TakeFromPile();
}

bool Deck::sidePileIsEmpty() {
    return pile.CardsInPile() == 0;
}

bool Deck::sidePileIsFull() {
    return pile.CardsInPile() == 5;
}