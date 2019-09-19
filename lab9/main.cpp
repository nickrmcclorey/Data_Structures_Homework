#include <iostream>
#include <fstream>
#include "Node.h"
#include "WordCount.h"
#include "input.h"
#include "BinaryTree.h"
using namespace std;

BinaryTree<WordCount> CountWords() {

    string userInput;
    fstream infile;
    while (!infile.is_open()) {
        cout << "What file do you want to read from?" << endl;
        getline(cin, userInput);
        infile.open(userInput);
        if (infile.fail()) {
            cout << "Failed to open file" << endl;
        }
    }

    BinaryTree<WordCount> allWords;
    string word;
    while (!infile.eof()) {
        infile >> word;
        WordCount temp(word);
        WordCount *wordObject = allWords.Find(temp);
        if (wordObject == nullptr) {
            allWords.Insert(temp);
        } else {
            wordObject->addCount();
        }
    }
    return allWords;
}

bool testBinaryTree(int array[], int size) {
    BinaryTree<int> tree;
    for (int k = 0; k < size; k++) {
        tree.Insert(array[k]);
        if (!tree.IsBalanced()) {
            return false;
        }
    }

    return true;
}

bool allTestsPassed() {
    int tests[4][3] = {{1, 2, 3},
                    {1, 3, 2},
                    {3, 2, 1},
                    {3, 1, 2}};
    for (int k = 0; k < 4; k++) {
        bool success = testBinaryTree(tests[k], 3);
        if (success == false) {
            return false;
        }
    }

    int array[6] = {2, 1, 5, 4, 3, 6};
    bool success = testBinaryTree(array, 6);
    if (success == false) {
        return false;
    }

    return true;
}

void runAllTests() {
    if (!allTestsPassed()) {
        cout << "Binary Tree test failed. Exiting..." << endl;
        exit(0);
    }
    cout << "All tests passed. No run time errors." << endl;
}

void searchForWord(BinaryTree<WordCount> &tree) {
    cout << "Enter the word you'd like to search for" << endl;
    string wordToFind;
    getline(cin, wordToFind);
    WordCount wordObject(wordToFind);
    WordCount* found = tree.Find(wordObject);
    if (found == nullptr) {
        cout << wordToFind << " wasn't found." << endl;
    } else {
        cout << "There are " << found->getCount() << " instance(s) of " << found->word << endl;
    }
}

void printTree(BinaryTree<WordCount> &tree) {
    int userInput = 0;
    while (userInput != 1 && userInput != 2) {
        cout << "Ascending or Descending?" << endl;
        cout << "[1] Ascending" << endl;
        cout << "[2] Descending" << endl;
        userInput = askInt();
    }
    Node<WordCount> *array = nullptr;
    if (userInput == 1) {
        array = tree.GetAllAscending();
    } else {
        array = tree.GetAllDescending();
    }

    for (int k = 0; k < tree.Size(); k++) {
        array[k].data.print();
    }
}

void menu(BinaryTree<WordCount> &tree) {

    int userResponse = 1;
    while (userResponse != 3) {
        cout << "Please select an option" << endl;
        cout << "[1] Search for a word" << endl;
        cout << "[2] List all words" << endl;
        cout << "[3] Exit" << endl;
        userResponse = askInt();
        if (userResponse == 1) {
            searchForWord(tree);
        } else if (userResponse == 2) {
            printTree(tree);
        } else if (userResponse != 3) {
            cout << "That's not a valid option" << endl;
        }
    }

}

int main() {
    runAllTests();
    BinaryTree<WordCount> tree = CountWords();
    menu(tree);
    cout << "goodbye" << endl;
    return 0;
}
