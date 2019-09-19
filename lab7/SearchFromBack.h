#pragma once
#include <stdexcept>
#include "OrderedList.h"
using namespace std;
extern const int MAX_ITEMS;

template <class T>
class SearchFromBack : public OrderedList<T> {
    public: 
    void AddItem(T itemToAdd);
    SearchFromBack();
};

template <class T>
SearchFromBack<T>::SearchFromBack() : OrderedList<T>::OrderedList() {

}

template <class T>
void SearchFromBack<T>::AddItem(T itemToAdd) {
    int index = MAX_ITEMS - 1;

    while (this->items[index] == nullptr && index >= 0) {
        index--;
    }
    if (index == MAX_ITEMS - 1) {
        throw new FullListException;
    }

    this->addOperations++;
    this->items[index + 1] = new T;
    *this->items[index + 1] = itemToAdd;
}
