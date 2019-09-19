#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Product.h"
using namespace std;

const int NUM_PRODS = 4;

string askForFileName() {
    string userInput;
    cout << "Enter the name of the file to read" << endl;
    cin >> userInput;
    return userInput;
}

string getFileContents() {

    fstream infile;
    while (true) {
        string filename = askForFileName();
        infile.open(filename.c_str(), ios::in);
        if (!infile.is_open()) {
            cout << "file wasn't found" << endl;
        } else {
            break;
        }
    }

    string entireFile = "";
    string oneline = "";
    while (!infile.eof()) {
        getline(infile, oneline);
        if (oneline.length() > 0) {
            entireFile.append(oneline + "\n");
        }
    }

    // remove trailing \n
    entireFile = entireFile.substr(0, entireFile.size() - 1);
    infile.close();
    return entireFile;
}

void printProductInformation(Product products[], int numTildas) {

    for (int k = 0; k < numTildas && k < NUM_PRODS; k++) {
        cout << "Product " << k + 1 << ":" << endl;
        cout << "ID: " << products[k].id << endl;
        cout << "Units: " << products[k].units << endl;
        cout << "Price: " << products[k].price << endl;
        cout << "Description: " << products[k].description << endl;
        string trueOrFalse = (products[k].taxExempt) ? "True" : "False";
        cout << "TaxExempt: " << trueOrFalse << endl << endl;;
    }
    
    if (numTildas > NUM_PRODS) {
        cout << "There are more than " << NUM_PRODS << " products in the file" << endl;
    } else if (numTildas < NUM_PRODS) {
        cout << "There are less than " << NUM_PRODS << " products in the file" << endl;
    }
}

int main() {

    // read in raw file contents
    string fileContents = getFileContents();

    // this is used to count the number of sections in each file
    // found this gem from https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string
    int numTildas = std::count(fileContents.begin(), fileContents.end(), '~');

    Product products[NUM_PRODS];
    // iterate over the sections of the string, which are seperated by a tilda "~"
    // take each section and pass it to the method Product.parseFileSection to populate the class
    int k = 0;
    for (k = 0; k < NUM_PRODS - 1 && k < numTildas - 1; k++) {
        products[k].parseFileSection(fileContents.substr(0, fileContents.find("~")));
        fileContents = fileContents.substr(fileContents.find("~") + 2);
    }
    products[k].parseFileSection(fileContents.substr(0, fileContents.find("~")));

    // print information about the products
    printProductInformation(products, numTildas);

    return 0;
}