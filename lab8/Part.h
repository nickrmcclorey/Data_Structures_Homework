#pragma once
#include <string>
using namespace std;

class Part {
    private:
        int partNumber;
        string description;
        double price;
        string UOM;
        int QuantityOnHand;
        int LeadTime;
    public:
        Part(int partNumberIn, string descriptionIn, double priceIn, string UOMin, int Quantity);
        string GetPartInfo();
        int GetPrice();
        bool InStock();
        bool Available(tm dueDate);
        bool operator<(Part other);
        bool operator>(Part other);
        bool operator==(Part other);
        void printContents();
};