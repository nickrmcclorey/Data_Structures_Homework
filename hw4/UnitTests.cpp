#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "Slot.h"
#include "DepthTable.h"
#include "LinearProbing.h"
using namespace std;

int main() {
    Slot slot;
    assert (slot.data == nullptr);
    assert (slot.occupied == false);

    LinearProbing table;
    DepthTable table1;
    srand(251398); // seed should not produce repeat integers for rand() in the first 400 calls
    for (int k = 0; k < 400; k++) {
        // inserting and removing and remove should all have the same
        // amount of checks if done immediatly after one another
        int value = rand();
        assert (table.Insert(value) == table.Find(value));
        assert (table.Find(value) == table.Remove(value));

        assert (table1.Insert(value) == table1.Find(value));
        assert (table1.Find(value) == table1.Remove(value));
    }

    // tables to test the print function
    LinearProbing printTest;
    DepthTable printTest1;
    for (int k = 0; k < 20; k++) {
        int value = rand();
        printTest.Insert(value);
        printTest1.Insert(value);
    }
    cout << "Linear Probing Print: " << endl;
    printTest.Print();
    cout << "Depth Table Print:" << endl;
    printTest1.Print();


    cout << "All Tests Passed! Give that man a cigar!" << endl;
    return 0;
}