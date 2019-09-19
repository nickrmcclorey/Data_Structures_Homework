#include <iostream>
#include <string>
#include "ComplexNumber.h"
using namespace std;

ComplexNumber askForCoordinates() {
    double x, y;
    string coordinateSystem = "";

    cout << "Would you like to enter cartesian coordinates or polar coordinates? (c/p)" << endl;
    cin >> coordinateSystem;
    if (coordinateSystem[0] == 'c') {
        cout << "Enter the real component: ";
        cin >> x;
        cout << "Enter the complex component: ";
        cin >> y;
        return ComplexNumber(x, y, true); 
    } else {
        cout << "Enter the magnitude (r): ";
        cin >> x;
        cout << "Enter the angle (phi): ";
        cin >> y;
        return ComplexNumber(x, y, false);
    }
}

int main() {
    ComplexNumber num1, num2;
    double real, imaginary, scale;
    string operator1, answer1;
    
    num1 = askForCoordinates();
    num1.print();
    
    do{
        cout << "Which operation to perform? (+,-,/,*,==): ";
        cin >> operator1;
        if(operator1 == "+") {
            cout << "Enter a complex number to subtract" << endl;
            num2 = askForCoordinates();
            num1 + num2;
            num1.print();
        }
        else if(operator1 == "-"){
            cout << "Enter a complex number to subtract" << endl;
            num2 = askForCoordinates();
            num1 - num2;
            num1.print();
        }
        else if(operator1 == "/"){
            cout << "Enter a scalar to divide by: ";
            cin >> scale;
            num1 = num1 / scale;
            num1.print();
        }
        else if(operator1 == "*"){
            cout << "Enter a scalar to multiply by: ";
            cin >> scale;
            num1 = num1 * scale;
            num1.print();
        }
        else if(operator1 == "=="){
            cout << "Enter a complex number to compare" << endl;
            num2 = askForCoordinates();
            cout << ((num1 == num2) ? "True" : "False") << endl;
        }
        else{
            cout << "Invalid input." << endl;
        }
        cout << "Would you like to perform another operation? (y/n) ";
        cin >> answer1;
    }
    while(answer1 == "y");
    
    cout << "final answer:" << endl;
    num1.print();
    cout << "number has an angle (phi) of " << num1.getPhi() << " degrees and a magnitude (r) of " << num1.getR() << endl;

    return 0;
}