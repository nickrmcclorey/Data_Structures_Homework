#pragma once
#include <iostream>
#include "HashTable.h"
#include "Slot.h"
using namespace std;

class LinearProbing : public HashTable {
    private:
        Slot array[500];
    public:
        LinearProbing();
        ~LinearProbing();
        int Insert(int);
        int Find(int);
        int Remove(int);
        void Print();
};
