#pragma once

class Node{
    public:
        int data;
        Node* next;
        Node(int i) {
            data = i;
            next = nullptr;
        }
};