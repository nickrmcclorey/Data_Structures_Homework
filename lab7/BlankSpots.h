#pragma once
#include <stdexcept>
#include "FullListException.h"
#include "OutOfRangeException.h"
#include "OrderedList.h"
using namespace std;
extern const int MAX_ITEMS;

template <class T>
class BlankSpots : public OrderedList<T> {
    public: 
        void AddItem(T itemToAdd);
        void RemoveItem(int index);
        BlankSpots();
};

template <class T>
BlankSpots<T>::BlankSpots() : OrderedList<T>::OrderedList() {}

template <class T>
void BlankSpots<T>::AddItem(T itemToAdd) {
    if (this->IsFull()) {
        throw new FullListException;
    }

    int index = MAX_ITEMS / 2;
    T* temp = this->items[index];
    this->items[index] = new T;
    *this->items[index] = itemToAdd;
    this->addOperations++;
    while (temp != nullptr) {
        if (index >= MAX_ITEMS - 1) {
            index = 0;
        } else {
            index++;
        }

        T* replaced = this->items[index];
        this->items[index] = temp;
        temp = replaced;
        this->addOperations++;
    }
}

template <class T>
void BlankSpots<T>::RemoveItem(int index) {
    if (index > MAX_ITEMS || index < 0) {
        throw new OutOfRangeException(index);
    } else if (this->items[index] == nullptr) {
        return;
    }

    delete this->items[index];
    this->items[index] = nullptr;
    this->removeOperations++;
}