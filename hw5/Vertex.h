#pragma once
#include "List.h"
using namespace std;

class Vertex {
    public:
        int data;
        bool visited;
        List<Vertex> outgoingEdges;
        List<Vertex> incomingEdges;
        
        bool operator==(const Vertex &other) {
            return data == other.data;
        }

        bool operator!=(const Vertex &other) {
            return data != other.data;
        }

        Vertex(int input) {
            data = input;
            visited = false;
        }
        ~Vertex() {

        }
};