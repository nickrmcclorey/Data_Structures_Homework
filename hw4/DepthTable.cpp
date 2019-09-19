#include "DepthTable.h"
using namespace std;

// the Slot class already has a constructor and
// array is defined in class definition
DepthTable::DepthTable() {}

// destructor will automatically be called on Slot class which will clean everything up
DepthTable::~DepthTable() {}

int DepthTable::Insert(int value) {
    int index = Hash(value, 100);
    int originalIndex = index;
    int checks = 1;
    int depth = 0;
    while (array[index][depth].data != nullptr) {
        checks++;
        if (depth >= 4) {
            depth = 0;
            index = (index == 99) ? 0 : index + 1;
        } else {
            depth++;
        }
        if (index == originalIndex && depth == 0) {
            throw new overflow_error("max size of Linear Probing hash table is 500");
        }
    }

    array[index][depth].data = new int(value);
    array[index][depth].occupied = true;
    return checks;
}

int DepthTable::Find(int value) {
    int index = Hash(value, 100);
    int originalIndex = index;
    int checks = 1;
    int depth = 0;
    while (array[index][depth].occupied && (array[index][depth].data == nullptr || *array[index][depth].data != value)) {
        checks++;
        if (depth >= 4) {
            depth = 0;
            index = (index == 99) ? 0 : index + 1;
        } else {
            depth++;
        }
        if (index == originalIndex && depth == 0) {
            return checks;
        }
    }

    return checks;
}

int DepthTable::Remove(int value) {
    int index = Hash(value, 100);
    int originalIndex = index;
    int checks = 1;
    int depth = 0;
    while (array[index][depth].data != nullptr && *array[index][depth].data != value) {
        checks++;
        if (depth >= 4) {
            depth = 0;
            index = (index == 99) ? 0 : index + 1;
        } else {
            depth++;
        }
        if (index == originalIndex) {
            return checks;
        }
    }

    delete array[index][depth].data;
    array[index][depth].data = nullptr;
    return checks;
}

// prints items 
void DepthTable::Print() {
    bool first = true;
    cout << "[ ";
    for (int k = 0; k < 100; k++) {
        for (int depth = 0; depth < 5; depth++) {
            if (array[k][depth].data != nullptr) {
                if (!first) {
                    cout << ", " << *array[k][depth].data;
                } else {
                    cout << *array[k][depth].data;
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
    }
    cout << " ]" << endl;
}