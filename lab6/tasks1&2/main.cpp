#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void gameIntro(){
    cout << "Welcome to the Tower of Hanoi" << endl;
    cout << "There are 3 basic rules:" << endl;
    cout << "1) Only one disk may be moved at a time." << endl;
    cout << "2) Each move must consist of taking the top disk from a stack and moving it to another stack." << endl;
    cout << "3) No larger disk may be placed onto a smaller disk." << endl;
    cout << "Let's begin!" << endl << endl;
}

void moveDisk(Stack<int> s[3]){
    int fromStack, toStack;
    bool cont = true;
    
    while(cont == true){
        cout << endl << "Which stack would you like to take from? ";
        cin >> fromStack;
        cout << "Which stack would you like to move to? ";
        cin >> toStack;
        if(fromStack == toStack){ //trying to put a disk on the same stack it was taken from
            cout << "You cannot put a disk on the same stack that you take it from." << endl;
        }
        else if(fromStack > 3 || toStack > 3 || fromStack < 0 || toStack < 0){
            cout << "Invalid stack selection." << endl;
        }
        else if(s[fromStack-1].isEmpty()){
            cout << "You cannot take a disk from an empty stack." << endl;
        }
        else if(!(s[toStack-1].isEmpty()) && (*s[toStack-1].top() < *s[fromStack-1].top())){ //trying to put a larger disk on a smaller disk
            cout << "You may not put a larger disk on top of a smaller disk." << endl;
        }
        else{
            s[toStack-1].push(s[fromStack-1].pop());
            cont = false;
        }
    }
}

template <class T>
void print(Stack<T> stacks[], int length) {
    for (int k = 0; k < length; k++) {
        cout << "<== Tower " << k+1 << " ==>" << endl;
        print(stacks[k]);
        cout << "--------------------" << endl;
    }
}

template <class T>
void print(Stack<T> stack) {
    for (int k = stack.nextIndex - 1; k >= 0; k--) {
        cout << *stack.array[k] << endl;
    }
}

void testStack() {

	Stack<int> x(2);
	cout << "1 = " << x.isEmpty() << endl;
	int* ptr = new int;
	*ptr = 4;
	x.push(ptr);
	x.push(new int);
	cout << "1 = " << x.isFull() << endl;
	ptr = x.pop();
	cout << "1 = " << x.length() << endl;
	
}


int main() {
    testStack();
    gameIntro();
    
    int disks;
    
    cout << "How many disks are on the stack? ";
    cin >> disks;
    
    Stack<int> stacks[3] {{disks}, {disks}, {disks}};
    
    for(int i = disks; i > 0; i--){
        int *counter = new int;
        *counter = i;
        stacks[0].push(counter);
    }
    
    print(stacks, 3);
    while(stacks[0].length() > 0 || stacks[1].length() > 0){ //game not finished (all disks not in stack 3)
        moveDisk(stacks);
        print(stacks, 3);
    }
    cout << "Good job. You moved the tower!" << endl;
    
    return 0;
}
    



