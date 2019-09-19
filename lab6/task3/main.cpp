#include <iostream>
#include <string>
#include "Stack.h"
#include "Block.h"
using namespace std;

void gameIntro(){
    cout << "Welcome to the Tower of Hanoi" << endl;
    cout << "There are 3 basic rules:" << endl;
    cout << "1) Only one disk may be moved at a time." << endl;
    cout << "2) Each move must consist of taking the top disk from a stack and moving it to another stack." << endl;
    cout << "3) No larger disk may be placed onto a smaller disk." << endl;
    cout << "Let's begin!" << endl << endl;
}

void moveDisk(Stack<Block> s[3], string turn){
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
        else if(fromStack > 5 || toStack > 5 || fromStack < 0 || toStack < 0){
            cout << "Invalid stack selection." << endl;
        }
        else if(s[fromStack-1].isEmpty()){
            cout << "You cannot take a disk from an empty stack." << endl;
        }
        else if(!(s[toStack-1].isEmpty()) && (s[toStack-1].top()->size < s[fromStack-1].top()->size)){ //trying to put a larger disk on a smaller disk
            cout << "You may not put a larger disk on top of a smaller disk." << endl;
        }
        else if (s[toStack-1].isFull()) {
            cout << "This tower is full" << endl;
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

void print(Stack<Block> stack) {
    for (int k = stack.nextIndex - 1; k >= 0; k--) {
        Block block = *stack.array[k];
        cout << block.size << " -> " << block.player << endl;
    }
}

int testStack() {

	Stack<int> x(2);
	cout << "1 = " << x.isEmpty() << endl;
	int* ptr = new int;
	*ptr = 4;
	x.push(ptr);
	x.push(new int);
	cout << "1 = " << x.isFull() << endl;
	ptr = x.pop();
	cout << "1 = " << x.length() << endl;
	
    return 0;
}

bool TowerIsComplete(Stack<Block> stack, string player) {
    if (!stack.isFull()) {
        return false;
    }

    for (int k = 0; k < stack.length(); k++) {
        if (stack.array[k]->player != player) {
            return false;
        }    
    }
    return true;
}

bool gameIsOver(Stack<Block> stacks[]) {
    bool player1Done = TowerIsComplete(stacks[4], "Player 1") ||
        TowerIsComplete(stacks[3], "Player 1");

    bool player2Done = TowerIsComplete(stacks[0], "Player 2") ||
        TowerIsComplete(stacks[1], "Player 2");

    return player1Done && player2Done;
}

int main() {
    testStack();
    gameIntro();
    
    int disks;
    
    cout << "How many disks are on the stack? ";
    cin >> disks;
    
    Stack<Block> stacks[5] {{disks}, {disks}, {disks}, {disks}, {disks}};
    
    const string player1 = "Player 1";
    const string player2 = "Player 2";
    for(int i = disks; i > 0; i--){
        stacks[0].push(new Block(i, player1));
        stacks[4].push(new Block(i, player2));
    }
    
    print(stacks, 5);
    string turn = player1;
    while(gameIsOver(stacks) == false){
        cout << "It's " << turn << "'s turn" << endl;
        moveDisk(stacks, turn);
        turn = (turn == player1) ? player2 : player1;
        print(stacks, 5);
    }
    cout << "Good job. You moved the towers!" << endl;
    
    return 0;
}
