#pragma once

template <class T>
class Node{
    public:
        T* data;
        Node<T>* next;
        Node(T* c) {
            data = c;
            next = nullptr;
        }
};