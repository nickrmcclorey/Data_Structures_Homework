#pragma once
class Slot {
    public:
        bool occupied;
        int *data;
        Slot() {
            occupied = false;
            data = nullptr;
        }
        ~Slot() {
            if (data != nullptr) {
                delete data;
            }
        }
};