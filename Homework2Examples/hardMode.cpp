#include <time.h>
#include <cstdlib>
#include "Wheel.h"

HardMode::() {
	maxValue = 10;
	minValue = 1;
}

int HardMode::spin(int resultValue) {
	srand(time(0));

	if (resultValue = 0) {
		maxValue = maxValue + 1;
		return rand() % maxValue + minValue;
	}
	else if(resultValue = 2) {
		return rand() % maxValue + minValue;
	}
	else {
		return rand() % maxValue + minValue;
	}
}
