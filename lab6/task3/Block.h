#pragma once
#include<string>
using namespace std;

class Block {
    public:
        int size;
        string player;
        Block(int sizeIn, string playerName) {
            size = sizeIn;
            player = playerName;
        }
};
