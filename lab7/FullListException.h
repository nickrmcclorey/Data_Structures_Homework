#pragma once
#include <string>

class FullListException {
    public:
        std::string message;
        FullListException();
};

FullListException::FullListException() {
    message = "List is full";
}