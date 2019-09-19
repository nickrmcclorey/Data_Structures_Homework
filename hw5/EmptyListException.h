#pragma once
#include <string>
using namespace std;

class EmptyListException {
    public:
        string message;
        EmptyListException() {
            message = "The List is empty";
        }
};