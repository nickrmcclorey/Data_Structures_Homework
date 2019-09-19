#include <iostream>
#include <string>
#include <ctime>
#include "Part.h"
using namespace std;

Part::Part(int partNumberIn, string descriptionIn, double priceIn, string UOMin, int Quantity = 0) {
    partNumber = partNumberIn;
    description = descriptionIn;
    price = priceIn;
    UOM = UOMin;
    QuantityOnHand = Quantity;
}

string Part::GetPartInfo() {
    return to_string(partNumber) + description;
}

int Part::GetPrice() {
    return price;
}

bool Part::InStock() {
    return QuantityOnHand > 0;
}

bool Part::Available(tm dueDate) {
    if (InStock()) {
        return true;
    }

    time_t now = time(0);
    time_t due = mktime(&dueDate);
    double daysDifference = difftime(due, now) / (60 * 60 * 24);
    return daysDifference > LeadTime;
}

bool Part::operator<(Part other) {
    return this->partNumber < other.partNumber;
}

bool Part::operator>(Part other) {
    return this->partNumber > other.partNumber;
}

bool Part::operator==(Part other) {
    return this->partNumber == other.partNumber;
}

void Part::printContents() {
    cout << partNumber << ":" << description;
}