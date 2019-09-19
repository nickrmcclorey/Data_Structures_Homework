#pragma once

class SidePile {
    private:
        int pile[5];
    public:
        SidePile();
        int CardsInPile();
        void AddToPile(int i);
        int TakeFromPile();
};