#include <iostream>
#include <math.h>
#include "ComplexNumber.h"
using namespace std;

ComplexNumber::ComplexNumber() {
    real = 0;
    imaginary = 0;
}

// if cartesian, x = real and y = imaginary, else x is the angle in degrees and y is the magnitude
ComplexNumber:: ComplexNumber(double x, double y, bool cartesian) {
    if (cartesian) {
        real = x;
        imaginary = y;
    } else {
        double magnitude = x;
        double angleRadians = y * M_PI / 180;
        imaginary = sin(angleRadians) * magnitude;
        real = cos(angleRadians) * magnitude;
    }
}

// setter for the real property
void ComplexNumber::setReal(double realIn) {
    real = realIn;
}

// getter for the real property
double ComplexNumber::getReal() {
    return real;
}

// setter for the imaginary property
void ComplexNumber::setImaginary(double imagine) {
    imaginary = imagine;
}

// getter for the imaginary property
double ComplexNumber::getImaginary() {
    return imaginary;
}

// prints the number in the form a + bi where a = real, and b = imaginary
void ComplexNumber::print() {
    cout << real << " + " << imaginary << "i" << endl;
}

// this adds the components of a complex number to the corresponding
// components of this complex number. It doesn't return anything 
// because the lab report specifically says to return void and add to this instance of the class
void ComplexNumber::operator+(ComplexNumber other) {
    real += other.getReal();
    imaginary += other.getImaginary();
}

// this adds the components of a complex number to the corresponding
// components of this complex number.
void ComplexNumber::operator-(ComplexNumber other) {
    real -= other.getReal();
    imaginary -= other.getImaginary();
}

// each component of this object is multiplied by a scalar.
// the new values are placed into a new Complex number and returned
ComplexNumber ComplexNumber::operator*(double scalar) {
    ComplexNumber newNumber(real * scalar, imaginary * scalar, true);
    return newNumber;
}

// each component of this object is divided by a scalar.
// the new values are placed into a new Complex number and returned
ComplexNumber ComplexNumber::operator/(double scalar) {
    ComplexNumber newNumber(real / scalar, imaginary / scalar, true);
    return newNumber;
}

// only returns true when both components of this object 
// equal the corresponding componenet of the other object
bool ComplexNumber::operator==(ComplexNumber other) {
    return (other.getImaginary() == imaginary && other.getReal() == real);
}

// calculates the magnitude of the polar coordinates
double ComplexNumber::getR() {
    return sqrt(pow(real, 2) + pow(real, 2));
}

// calculates the angle of the polar coordinates in degrees
double ComplexNumber::getPhi() {
    // angle is in radians
    double angle = atan(imaginary / real);
    return angle * 180 / M_PI;
}