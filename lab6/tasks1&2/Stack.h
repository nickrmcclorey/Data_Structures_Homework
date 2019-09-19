#include "StackOverflowException.h"
#include "StackUnderflowException.h"
using namespace std;
#pragma once
template<class T>
class Stack {
    private:
        T** array;
        int capacity;
        int nextIndex;
    public:
        Stack(int);
        void push(T*);
        T* pop();
        T* top();
        int length();
        void empty();
        bool isFull();
        bool isEmpty();
        
        template <class S>
        friend void print(Stack<S>);
};


template <class T>
Stack<T>::Stack(int size) {
    array = new T*[size];
    capacity = size;
    nextIndex = 0;
}

template <class T>
void Stack<T>::push(T* ptr) {
    if (this->isFull()) {
        throw new StackOverflowException(capacity);
    }

    array[nextIndex] = ptr;
    nextIndex++;
}

template <class T>
T* Stack<T>::pop() {
    if (this->isEmpty()) {
        throw new StackUnderflowException();
    }

    nextIndex--;
    return array[nextIndex];
}

template <class T>
T* Stack<T>::top() {
    if (this->isEmpty()) {
        throw new StackUnderflowException(); // TODO: Create custom class for this
    }

    return array[nextIndex - 1];
}

template <class T>
bool Stack<T>::isEmpty() {
    return nextIndex == 0; 
}

template <class T>
bool Stack<T>::isFull() {
    return nextIndex == capacity;
}

template <class T>
int Stack<T>::length() {
    return nextIndex;
}

template <class T>
void Stack<T>::empty() {
    for (int k = 0; k < this->length(); k++) {
        delete array[k];
    }
}


