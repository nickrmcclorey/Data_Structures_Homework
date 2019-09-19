#pragma once

class Wheel {
private:

    int maxValue;
    int minValue;
    
public:

    int spin();
    Wheel();
    Wheel(int min, int max);
    void setMaxValue(int input);
    void setMinValue(int input);
    int getMaxValue();
    int getMinValue();
};