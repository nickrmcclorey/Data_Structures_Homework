#include <iostream>
#include <string>
#include "List.h"
#include "Part.h"
using namespace std;

Part* CreatePart(){
    int partNumberIn, Quantity; 
    string descriptionIn, UOMin;
    double priceIn;
    
    cout << "Enter part number: ";
    cin >> partNumberIn;
    cout << "Enter description: ";
    cin >> descriptionIn;
    cout << "Enter price: ";
    cin >> priceIn;
    cout << "Enter unit of measure: ";
    cin >> UOMin;
    cout << "Enter quantity: ";
    cin >> Quantity;
    Part* partIn = new Part(partNumberIn, descriptionIn, priceIn, UOMin, Quantity);
    
    return partIn;
}

Part* CreateMinimalPart() {
    int partNumber = 0;
    cout << "Enter the part number: ";
    cin >> partNumber;
    return new Part(partNumber, "", 0, "", 0);
}

void PromptInput(List<Part> &list){
    string userIn;
    
    do{
        cout << "Choose: " << endl;
        cout << "1 for AddItem: Adds an item to the list" << endl;
        cout << "2 for GetItem: Removes a given item from the list and returns it" << endl;
        cout << "3 for IsInList: Checks if a given item is in the list" << endl;
        cout << "4 for IsEmpty: Checks if the list is empty" << endl;
        cout << "5 for Size: Returns the number of elements in the list" << endl;
        cout << "6 for SeeNext: Checks and returns the next value of a stored pointer" << endl;
        cout << "7 for SeeAt: Checks the value at a given index and stores the location in the pointer" << endl;
        cout << "8 for Reset: Resets the pointer for the SeeNext and SeeAt functions to point the the first item in the list" << endl;
        cout << "9 for printContents: Prints the contents" << endl;
        cout << "10 to exit" << endl;
        cin >> userIn;
        
        if(userIn == "1"){
            list.AddItem(CreatePart());
        }
        else if(userIn == "2"){
            list.GetItem(CreateMinimalPart())->printContents();
            cout << endl << "Item was removed" << endl;
        }
        else if(userIn == "3"){
            if(list.IsInList(CreateMinimalPart())){
                cout << "Part is in the list." << endl;
            }
            else{
                cout << "Part is not in the list." << endl;
            }
        }
        else if(userIn == "4"){
            if(list.IsEmpty()){
                cout << "List is empty." << endl;
            }
            else{
                cout << "List is not empty." << endl;
            }
        }
        else if(userIn == "5"){
            cout << "Size: " << list.Size() << endl;
        }
        else if(userIn == "6"){
            Part* part = list.SeeNext();
            if (part != nullptr) {
                part->printContents();
                cout << endl; 
            } else {
                cout << "seeNext() returned null." << endl;
            }
        }
        else if(userIn == "7"){
            int index;
            cout << "Enter the index to check at." << endl;
            cin >> index;
            list.seeAt(index)->printContents();
            cout << endl;
        }
        else if(userIn == "8"){
            list.Reset();
        }
        else if (userIn == "9"){
            list.printContents();
        }
        else if(userIn == "10"){
            cout << "Exiting." << endl;
        }
        else{
            cout << "Invalid input." << endl;
        }
    }
    while(userIn != "10");
}

int main() {
    List<Part> list1;
    PromptInput(list1);
    return 0;
}