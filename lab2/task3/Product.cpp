#include <string>
#include <iostream>
#include <sstream>
#include "Product.h"
using namespace std;

// converts a string to a number
int toInt(string num_s) { 
	istringstream raw(num_s); // create a stream with raw in it
	int toReturn = 0; // declare the variable to return
	raw >> toReturn; // put the string number into the int variable
	return toReturn; // return int
}

double toDouble(string num_s) { 
	istringstream raw(num_s); // create a stream with raw in it
	double toReturn = 0.0; // declare the variable to return
	raw >> toReturn; // put the string number into the int variable
	return toReturn; // return int
}

void Product::setSales() {
    this->sales = this->units * this->price;
}

void Product::parseFileSection(string fileContents) {
    fileContents = fileContents.substr(fileContents.find("ID:") + 4);
    this->id = toInt(fileContents.substr(0, fileContents.find("\n")));
    fileContents = fileContents.substr(fileContents.find("Units:") + 7);
    this->units = toInt(fileContents.substr(0, fileContents.find("\n")));
    fileContents = fileContents.substr(fileContents.find("Price:") + 7);
    this->price = toDouble(fileContents.substr(0, fileContents.find("\n")));
    fileContents = fileContents.substr(fileContents.find("Description:") + 13);
    this->description = fileContents.substr(0, fileContents.find("\n"));
    fileContents = fileContents.substr(fileContents.find("TaxExempt:") + 11);
    
    if (fileContents.find("True") != string::npos) {
        this->taxExempt = true;
    } else if (fileContents.find("False") != string::npos) {
        this->taxExempt = false;
    }
    this->setSales();
}