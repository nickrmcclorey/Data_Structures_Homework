#pragma once
using namespace std;

// this abstract class is inherited by LinearProbing and DepthTable
class HashTable {
    public:
        virtual int Insert(int) = 0;
        virtual int Find(int) = 0;
        virtual int Remove(int) = 0;
        virtual void Print() = 0;
        int Hash(int valueToHash, int maxValue) {
            return valueToHash % maxValue;
        }
};
