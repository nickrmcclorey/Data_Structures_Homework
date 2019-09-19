#include "List.h"


void List::Insert(char c){
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        Node* temp = head;
        while(temp->next != null){
            temp = temp->next;
        }
        temp->next = adder;
    }
}

void List::InsertFront(char c){
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        adder->next = head;
        head = adder;
    }
}

void List::InsertOrdered(char c){ //alphabetically ordered
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        Node* temp = head;
        if(c < head->data){
            adder->next = temp;
            head = adder;
        }
        else{
            while(temp->next != null){
                if(temp->next->data > c){
                    adder->next = temp->next;
                    temp->next = adder;
                }
                temp = temp->next;
                if(temp->next == null){
                    temp->next = adder;
                }
            }
        }
    }
}

char List::Remove(char c){
    if(head == null){
        //throw empty list exception
    }
    if(head->data == c){
        //head = head->next; would result in a memory leak
        Node* temp = head;
        head = head->next;
        char retval = temp->data;
        delete temp;
        return retval;
    }
    else{
        Node* ptr = head;
        while(ptr->next != null){
            if(ptr->next->data == c){
                Node* temp = ptr->next;
                ptr->next = temp->next;
                char retval = temp->data;
                delete temp;
                return retval;
            }
            ptr = ptr->next;
        }
    }
}

void List::makeEmpty(){
    while(head->data != null){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

char List::getNext(){
    if(curr == null){
        curr = head;
    }
    if(curr->next == null){
        return curr->data;
    }
    else{
        curr = curr->next;
        return curr->data;
    }
}

void List::circularInsert(char c){
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = adder;
        temp = temp->next;
        temp->next = head;
    }
}

void List::circularInsertFront(char c){
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        adder->next = head;
        Node* temp = head;
        while(temp != head){
            temp = temp->next;
        }
        head = adder;
        temp->next = head;
    }
}

void List::doubleCircularInsertFront(char c){
    Node* adder = new Node(c);
    if(head == null){
        head = adder;
    }
    else{
        head->prev->next = adder;
        adder->prev = head->prev
        head->prev = adder;
        adder->next = head;
        head = adder;
        
    }
}