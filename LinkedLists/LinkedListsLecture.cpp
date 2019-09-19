#include <iostream>
#include "Node.h"
//#include "Node.cpp"
#include "List.h"
#include "List.cpp"
using namespace std;

int main(){
    List ll;
    ll.InsertOrdered('M');
    ll.InsertOrdered('A');
    ll.InsertOrdered('C');
    ll.InsertOrdered('Z');
    cout << ll.head;
    return 0;
}