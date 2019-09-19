#ifndef ComplexNumber_h
#define ComplexNumber_h

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    void setReal(double realIn);
    void setImaginary(double imagine);
    double getReal();
    double getImaginary();

    ComplexNumber();
    ComplexNumber(double x, double y, bool cartesian);

    void print();

    void operator+(ComplexNumber other);
    void operator-(ComplexNumber other);
    ComplexNumber operator*(double scalar);
    ComplexNumber operator/(double scalar);
    bool operator==(ComplexNumber other);

    double getR(); // returns magnitude of polar coordinates
    double getPhi(); // returns angle of polar coordinates in degrees
};

#endif