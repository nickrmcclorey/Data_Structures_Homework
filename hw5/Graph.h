#pragma once
#include "Vertex.h"
using namespace std;


class Graph{
    private:
        List<Vertex> vertices;
        Vertex* findVertex(int one);
        void depthFirstSearch(Vertex* vertex);
    public:
        ~Graph();
        void addEdge(int from, int to);
        void removeEdge(int from, int to);
        bool hasEdge(int from, int to);
        List<Vertex>* outEdges(int from);
        List<Vertex>* inEdges(int to);
        void depthFirstSearch();
        void breadthFirstSearch();
        void resetVistedFlags();
};