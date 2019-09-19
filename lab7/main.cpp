#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>
#include "OrderedList.h"
#include "SearchFromBack.h"
#include "TestTemplate.h"
#include "BlankSpots.h"
using namespace std;

const int MAX_ITEMS = 20;

void testOrderedList() {
    OrderedList<int> list;
    list.AddItem(3);
    list.AddItem(87);
    list.RemoveItem(1);
    list.AddItem(5);
    list.RemoveItem(0);
    list.AddItem(8);
}

TestTemplate generateRandomTests() {
    
    random_device rd;
    mt19937 eng{static_cast<long unsigned int>(time(0))};
    uniform_int_distribution<> distr(0, MAX_ITEMS - 1);
    
    TestTemplate tests;
    for (int k = 0; k < 30; k++) {
        tests.insertions[k] = distr(eng);
    }

    for (int k = 0; k < 25; k++) {
        tests.removeIndexes[k] = distr(eng);
    }

    // generate vector with correct amount of operations
    vector<bool> bools(55);
    int k = 0;
    for (k = 0; k < 30; k++) {
        bools[k] = true;
    }
    for (k = 30; k < 55; k++) {
        bools[k] = false;
    }

    // shuffle the vector and copy it to an array in the tests object
    random_shuffle(bools.begin(), bools.end());
    for (int k = 0; k < bools.size(); k++) {
        tests.action[k] = bools[k];
    }

    return tests;
}

void testList(OrderedList<int>* list, TestTemplate tests) {

    int insertionIndex = 0;
    int removeIndex = 0;
    for (int k = 0; k < 55; k++) {
        if (tests.action[k]) {
            list->AddItem(tests.insertions[insertionIndex]);
            insertionIndex++;
        } else {
            list->RemoveItem(tests.removeIndexes[removeIndex]);
            removeIndex++;
        }
    }

    list->PrintResult();
}

int main(){
    OrderedList<int>* orderedList = new OrderedList<int>();
    OrderedList<int>* searchFromBack = new SearchFromBack<int>();
    OrderedList<int>* blankSpots = new BlankSpots<int>();
    
    TestTemplate tests = generateRandomTests();

    cout << "OrderedList class: " << endl;
    testList(orderedList, tests);
    cout << "searchFromBack class:" << endl;
    testList(searchFromBack, tests);
    cout << "blankSpots class:" << endl;
    testList(blankSpots, tests);

    return 0;
}

