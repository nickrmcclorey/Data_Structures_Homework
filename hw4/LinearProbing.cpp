#include <iostream>
#include "LinearProbing.h"
#include "Slot.h"
using namespace std;

// Slot already has a constructor so we don't really need to do anything
LinearProbing::LinearProbing() {}

// destructor of Slot class will clean everything up
LinearProbing::~LinearProbing() {}

int LinearProbing::Find(int value) {
    int index = Hash(value, 500);
    int originalIndex = index;
    int checks = 1;
    while (array[index].occupied && (array[index].data == nullptr || *array[index].data != value)) {
        checks++;
        index = (index == 499) ? 0 : index + 1;
        if (index == originalIndex) {
            break;
        }
    }

    return checks;
}

int LinearProbing::Insert(int value) {
    int index = Hash(value, 500);
    int originalIndex = index;
    int checks = 1;
    while (array[index].data != nullptr) {
        checks++;
        index = (index == 499) ? 0 : index + 1;
        if (index == originalIndex) {
            throw new overflow_error("max size of Linear Probing hash table is 500");
        }
    }

    array[index].data = new int(value);
    array[index].occupied = true;
    return checks;
}

int LinearProbing::Remove(int value) {
    int index = Hash(value, 500);
    int originalIndex = index;
    int checks = 1;
    while (array[index].occupied && *array[index].data != value) {
        checks++;
        index = (index == 499) ? 0 : index + 1;
        if (index == originalIndex) {
            break;
        }
    }

    if (*array[index].data == value) {
        delete array[index].data;
        array[index].data = nullptr;
        int nextCollisionLocation = (index == 499) ? 0 : index + 1;
    }

    return checks;
}

// prints arrays contents
void LinearProbing::Print() {
    bool first = true;
    cout << "[ ";
    for (int k = 0; k < 500; k++) {
        if (array[k].data != nullptr) {
            if (!first) {
                cout << ", " << *array[k].data;
            } else {
                cout << *array[k].data;
                first = false;
            }
        } else {
            if (!first) {
                cout << ", -";
            } else {
                cout << "-";
                first = false;
            }
        }
    }
    cout << " ]" << endl;
}