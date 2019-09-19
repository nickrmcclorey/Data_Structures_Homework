#include <iostream>
#include <string>
#include <ctime>
#include "Student.h"
using namespace std;

Student::Student(string MnumberIn, string nameIn, int ageIn) {
    Mnumber = MnumberIn;
    name = nameIn;
    age = ageIn;
}

void Student::print() {
    cout << Mnumber << " - " << name << " - " << age << endl; 
}

string Student::GetMnumber() {
    return Mnumber;
}

string Student::GetName() {
    return name;
}

bool Student::operator<(Student other) {
    return this->Mnumber < other.Mnumber;
}

bool Student::operator>(Student other) {
    return this->Mnumber > other.Mnumber;
}

bool Student::operator==(Student other) {
    return this->Mnumber == other.Mnumber;
}

bool Student::operator!=(Student other) {
    return this->Mnumber != other.Mnumber;
}

void Student::printContents() {
    cout << Mnumber << ":" << Mnumber;
}