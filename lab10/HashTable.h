#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Slot.h"
using namespace std;

template <class T>
class HashTable {
    protected:
        Slot<T> *array;
        int Hash(string input);
    private:
        int maxSize;
        int NextIndex(int x);
    public:
        int comparisons;
        HashTable(int arraySize = 100);
        virtual ~HashTable();
        void AddItem(T *newElement);
        int GetLength();
        T* RemoveItem(T value);
        T* GetItem(T value);
};

template <class T>
HashTable<T>::HashTable(int arraySize) {
    maxSize = arraySize;
    array = new Slot<T>[arraySize];
    comparisons = 0;
}

template <class T>
int HashTable<T>::Hash(string input) {
    int sum = 0;
    for (int k = 0; k < input.size(); k++) {
        sum += input[k];
    }

    return sum % maxSize;
}

template <class T>
int HashTable<T>::NextIndex(int x) {
    if (x >= maxSize - 1) {
        return 0;
    } else {
        return x + 1;
    }
}

template <class T>
void HashTable<T>::AddItem(T *newElement) {
    int index = Hash(*newElement);
    int originalIndex = index;
    while (array[index].data != nullptr) {
        index = NextIndex(index);

        if (index == originalIndex) {
            throw new overflow_error("Max size of table is " + to_string(maxSize));
        }
    }

    array[index].data = newElement;
    array[index].occupied = true;
}

template <class T>
int HashTable<T>::GetLength() {
    int count = 0;
    for (int k = 0; k < maxSize; k++) {
        if (array[k].data != nullptr) {
            count++;
        }
    }

    return count;
}

template <class T>
T* HashTable<T>::RemoveItem(T value) {
    int index = Hash(value);
    int originalIndex = index;
    while (array[index].occupied && array[index].data != nullptr && *array[index].data != value) {
        index = NextIndex(index);
        if (index == originalIndex) {
            return nullptr;
        }
    }

    if (array[index].data == nullptr) {
        return nullptr;
    } else {
        T* temp = array[index].data;
        array[index].data = nullptr;
        return temp;
    }
}

template <class T>
T* HashTable<T>::GetItem(T value) {
    int index = Hash(value);
    int originalIndex = index;
    while (array[index].occupied && array[index].data != nullptr && *array[index].data != value) {
        index = NextIndex(index);
        comparisons++;
        if (index == originalIndex) {
            return nullptr;
        }
    }

    if (array[index].data == nullptr) {
        return nullptr;
    } else {
        return array[index].data;
    }
}

template <class T>
HashTable<T>::~HashTable() {
    delete [] array;
}
