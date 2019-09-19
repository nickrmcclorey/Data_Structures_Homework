#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "HashTable.h"
#include "Student.h"
#include "ChainedTable.h"
using namespace std;

Student* askForStudentInfo() {
    string mNum, name;
    int age;
    cout << "What's the M number?" << endl;
    cin >> mNum;
    cout << "What's the name?" << endl;
    cin >> name;
    cout << "What's the age?" << endl;
    cin >> age;
    return new Student(mNum, name, age);
}

void PromptInput(HashTable<Student> &table){
    string userIn;
    
    do{
        cout << "Choose: " << endl;
        cout << "1 for AddItem: Adds an item to the list" << endl;
        cout << "2 for RemoveItem: Removes a given item from the list and returns it" << endl;
        cout << "3 for GetItem: Checks if a given item is in the list" << endl;
        cout << "4 for Size: Returns the number of elements in the list" << endl;
        cout << "5 to exit" << endl;
        cin >> userIn;
        
        if(userIn == "1"){
            Student* newStudent = askForStudentInfo();
            table.AddItem(newStudent);
        }
        else if(userIn == "2"){
            Student* student = askForStudentInfo();
            Student* removed = table.RemoveItem(*student);
            if (removed != nullptr) {
                cout << "Student removed:" << endl;
                removed->print();
                delete removed;
            } else {
                cout << "Student wasn't found" << endl;
            }
            delete student;
        }
        else if(userIn == "3"){
            Student* student = askForStudentInfo();
            Student* found = table.GetItem(*student);
            if (found != nullptr) {
                cout << "Student found" << endl;
                found->print();
            } else {
                cout << "Student wasn't found" << endl;
            }

            delete student;
        }
        else if(userIn == "4"){
            cout << "The size is " << table.GetLength() << endl;
        }
    }
    while(userIn != "5");
}

void MeasurePerformance(int arraySize, int seed) {
    HashTable<Student> hashtable(arraySize);
    ChainedTable<Student> chainedtable(arraySize);
    Student students[50];
    srand(seed);
    
    for (int k = 0; k < 50; k++) {
        int mNumber = rand() % 89999999 + 10000000; 
        int age = rand() % 10 + 18;
        string name = "";
        Student* student = new Student("M" + to_string(mNumber), name, age);
        hashtable.AddItem(student);
        chainedtable.AddItem(student);
        students[k] = *student;
    }

    for (int k = 0; k < 50; k++) {
        Student* found = hashtable.GetItem(students[k]);
        found = chainedtable.GetItem(students[k]);
        if (*found != students[k]) {
            cout << "something went wrong" << endl;
        }
    }
    cout << "Comparisons: " << hashtable.comparisons << endl;
    cout << "Comparisons: " << chainedtable.comparisons << endl;
}

int main() {
    int seed = time(0);
    MeasurePerformance(150, seed);
    MeasurePerformance(200, seed);
    MeasurePerformance(250, seed);
    ChainedTable<string> y(2);
    string* x = new string;
    y.AddItem(x);
    y.RemoveItem(*x);
    y.GetItem(*x);
    HashTable<Student> table;
    PromptInput(table);
    return 0;
}
