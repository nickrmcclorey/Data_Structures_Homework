#pragma once
#include <string>
using namespace std;

class Student {
    private:
        string Mnumber;
        string name;
        int age;
    public:
        Student(string MnumberIn = "00000000", string nameIn = "Undefined", int ageIn = 0);
        void print();
        string GetStudentInfo();
        string GetMnumber();
        string GetName();
        bool operator<(Student other);
        bool operator>(Student other);
        bool operator==(Student other);
        bool operator!=(Student other);
        void printContents();
        operator string() const { return Mnumber; }
        operator string&() { return Mnumber; }
};