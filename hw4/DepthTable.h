#pragma once
#include <iostream>
#include "Slot.h"
#include "HashTable.h"
using namespace std;

class DepthTable : public HashTable {
    private:
        Slot array[100][5];
    public:
        DepthTable();
        ~DepthTable();
        int Insert(int);
        int Find(int);
        int Remove(int);
        void Print();
};
