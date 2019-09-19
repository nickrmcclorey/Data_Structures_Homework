#pragma once

class List{
    public:
        Node* head;
        int length;
        Node* curr;
        Node* tail;
        void Insert(char c);
        void InsertFront(char c);
        void InsertOrdered(char c);
        char Remove(char c);
        void makeEmpty();
        char getNext();
        void circularInsert(char c);
        void circularInsertFront(char c);
};