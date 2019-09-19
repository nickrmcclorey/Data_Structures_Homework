#include <time.h>
#include <cstdlib>
#include "Wheel.h"

Wheel::Wheel() {
    maxValue = 10;
    minValue = 1;
}

Wheel::Wheel(int min, int max) {
    maxValue = max;
    minValue = min;
}

int Wheel::spin() {
    srand(time(0));
    return rand() % maxValue + minValue;
}

void Wheel::setMaxValue(int input) {
    maxValue = input;
}
void Wheel::setMinValue(int input) {
    minValue = input;
}
int Wheel::getMaxValue() {
    return maxValue;
}
int Wheel::getMinValue() {
    return minValue;
}