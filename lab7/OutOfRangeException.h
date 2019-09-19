#pragma once
#include <string>
using namespace std;

extern const int MAX_ITEMS;

class OutOfRangeException {
    public:
        string message;
        OutOfRangeException(int indexReceived);
};

OutOfRangeException::OutOfRangeException(int indexReceived) {
    message = "valid indexes range from 0 to " + to_string(MAX_ITEMS) + ". Index received was " + to_string(indexReceived); 
}