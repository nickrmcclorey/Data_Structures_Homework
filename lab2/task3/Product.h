#ifndef Product_h
#define Product_h
#include <string>
using namespace std;

class Product {
public:
    int id;
    int units;
    double price;
    double sales;
    bool taxExempt;
    string description;

    void setSales();
    void parseFileSection(string);
};

int toInt(string num_s);
double toDouble(string num_s);
#endif