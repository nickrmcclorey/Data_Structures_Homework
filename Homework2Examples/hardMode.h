#pragma once
#pragma once
#include "Wheel.h"

class HardMode : public Wheel {
private:
	int maxValue;
	int minValue;
public:
	int spin(int);
	HardMode();
	HardMode(int min, int max);
};
