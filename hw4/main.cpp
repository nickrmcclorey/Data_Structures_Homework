#include <iostream>
#include <ctime>
#include "HashTable.h"
#include "LinearProbing.h"
#include "DepthTable.h"
using namespace std;

// operates on a hash table and prints results about efficiency
int testHashTables(int list[100], HashTable* table) {
    int sum = 0;
    for (int k = 0; k < 50; k++) {
        sum += table->Insert(list[k]);
    }

    cout << "Spots checked after inserting 50 items: " << sum << endl;
    sum = 0;
    int count = 0;

    for (int k = 0; k < 50; k++) {
        if (list[k] % 7 == 0) {
            sum += table->Remove(list[k]);
            count++;
        }
    }

    cout << "Spots checked after removing " << count << " items: " << sum << endl;
    sum = 0;

    for (int k = 50; k < 100; k++) {
        sum += table->Insert(list[k]);
    }

    cout << "Spots checked after inserting 50 more items: " << sum << endl;
    sum = 0;
    count = 0;

    for (int k = 0; k < 100; k += 9) {
        if (k % 9 == 0 && list[k] % 7 != 0) {
            sum += table->Find(list[k]);
            count++;
        }
    }

    cout << "Spots checked after finding " << count <<" items: " << sum << endl;
}

int main() {
    srand(time(0));
    int list[100];
    for (int k = 0; k < 100; k++) {
        list[k] = rand();
    }

    LinearProbing table1;
    DepthTable table2;
    cout << endl << "running tests on Linear Probing" << endl;
    testHashTables(list, &table1);
    cout << endl << "running tests on Depth Table" << endl;
    testHashTables(list, &table2);
    
    return 0;
}