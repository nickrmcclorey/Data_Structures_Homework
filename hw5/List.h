#pragma once
#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
#include "EmptyListException.h"
using namespace std;

template <class T>
class List{
    private:
        Node<T>* head;
        Node<T>* curr;
    public:
        List();
        ~List();
        void AddItem(T* c);
        void AddFront(T* item);
        T* GetItem(T* c);
        void makeEmpty();
        T* SeeNext();
        void Reset();
        T* Remove(T* c);
        T* RemoveFront();
        bool IsInList(T* i);
        bool IsEmpty();
        int Size();
        T* seeAt(int i);
        void printContents();
};


template <class T>
List<T>::List() {
    head = nullptr;
    curr = nullptr;
}

template <class T>
void List<T>::AddItem(T* c){
    Node<T>* adder = new Node<T>(c);
    if(head == nullptr){
        head = adder;
        curr = adder;
    }
    else{
        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = adder;
    }
}

template <class T>
void List<T>::AddFront(T* item) {
    Node<T>* adder = new Node<T>(item);
    adder->next = head;
    head = adder;
}

template <class T>
T* List<T>::Remove(T* c){
    if(IsEmpty()){
        return nullptr;
    }
    if(*head->data == *c){
        T* retval = head->data;
        RemoveFront();
        return retval;
    }
    else{
        Node<T>* ptr = head;
        while(ptr->next != nullptr){
            if(*ptr->next->data == *c){
                Node<T>* temp = ptr->next;
                ptr->next = temp->next;
                T* retval = temp->data;
                delete temp;
                return retval;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }
}

template <class T>
T* List<T>::RemoveFront() {
    if (head == nullptr) {
        return nullptr;
    }
    Node<T>* temp = head;
    head = head->next;
    T* retval = temp->data;
    delete temp;
    return retval;
}

template <class T>
void List<T>::makeEmpty(){
    while(head != nullptr){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    curr = nullptr;
}

template <class T>
T* List<T>::SeeNext(){
    if (IsEmpty() || curr == nullptr) {
        return nullptr;
    }

    T* returnValue = curr->data;
    curr = curr->next;
    return returnValue;
}

template <class T>
void List<T>::Reset(){
    curr = head;
}

template <class T>
bool List<T>::IsInList(T* i){
    Node<T> *temp = head;
    while(temp != nullptr){
        if(*temp->data == *i){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool List<T>::IsEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

template <class T>
int List<T>::Size() {
    Node<T>* current = head;
    int numNodes = 0;
    while (current != nullptr) {
        numNodes++;
        current = current->next;
    }

    return numNodes;
}

template <class T>
T* List<T>::seeAt(int i){
    if(IsEmpty()){
        throw new EmptyListException;
    }
    int counter = 0;
    Node<T> *temp = head;
    while(counter < i && temp->next != nullptr){
        temp = temp->next;
        counter += 1;
    }
    if(counter < i){
        throw out_of_range("List's size is " + to_string(counter) + ", Index received: " + to_string(i));
    }
    curr = temp;
    return temp->data;
}

template <class T>
List<T>::~List() {
    makeEmpty();
}

template <class T>
T* List<T>::GetItem(T* toRemove) {
    
    Node<T>* searcher = head;
    while (searcher != nullptr && *searcher->data != *toRemove) {
        searcher = searcher->next;
    }
    if (searcher == nullptr) {
        return nullptr;
    }
    return searcher->data;
}