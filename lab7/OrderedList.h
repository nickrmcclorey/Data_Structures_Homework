#pragma once
#include "OutOfRangeException.h"
#include "FullListException.h"
using namespace std;
extern const int MAX_ITEMS;

template <class T>
class OrderedList {
    public:
        T** items;
        int removeOperations;
        int addOperations;
        
        OrderedList();
        virtual void AddItem(T itemToAdd);
        virtual void RemoveItem(int index);
        void MakeEmpty();
        void PrintResult();
        bool IsEmpty();
        bool IsFull();
};

template <class T>
OrderedList<T>::OrderedList() {
    items = new T*[MAX_ITEMS];
    removeOperations = 0;
    addOperations = 0;
    for (int k = 0; k < MAX_ITEMS; k++) {
        items[k] = nullptr;
    }
}

template <class T>
void OrderedList<T>::AddItem(T itemToAdd) {
    if (this->IsFull()) {
        throw new FullListException;
    }

    int index = 0;
    while (items[index] != nullptr && index < MAX_ITEMS) {
        index++;
    }

    addOperations++;
    items[index] = new T;
    *items[index] = itemToAdd;
}

template <class T>
void OrderedList<T>::RemoveItem(int index) {
    if (index > MAX_ITEMS || index < 0) {
        throw new OutOfRangeException(index);
    } else if (items[index] == nullptr) {
        return;
    }
    delete items[index];
    items[index] = nullptr;

    while (index + 1 < MAX_ITEMS && items[index + 1] != nullptr) {
        removeOperations++;
        items[index] = items[index + 1];
        index++;
    }

    if (index < MAX_ITEMS) {
        removeOperations++;
        items[index] = nullptr;
    }
}

template <class T>
void OrderedList<T>::MakeEmpty() {
	for (int k = 0; k < MAX_ITEMS; k++) {
        delete items[k];
		items[k] = nullptr;
	}
}

template <class T>
void OrderedList<T>::PrintResult(){
    cout << "\tAddItem Operations: " << addOperations << endl;
    cout << "\tRemoveItem Operations: " << removeOperations << endl;
    cout << "\tTotal Operations: " << addOperations + removeOperations << endl;
}

template <class T>
bool OrderedList<T>::IsEmpty(){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(items[i] != nullptr){
            return false;
        }
    }
    return true;
}

template <class T>
bool OrderedList<T>::IsFull(){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(items[i] == nullptr){
            return false;
        }
    }
    return true;
}
