#pragma once

template <class T>
class Slot {
    public:
        bool occupied;
        T *data;
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