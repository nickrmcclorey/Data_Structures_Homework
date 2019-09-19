#include <iostream>
#include "Graph.h"
#include "Vertex.h"
using namespace std;

// returns a pointer to a pointer with the value passed in
// if it doesn't exist, nullptr is returned
Vertex* Graph::findVertex(int one) {
    Vertex toCompare(one);
    Vertex* found = vertices.GetItem(&toCompare);
    return found;
}

void Graph::addEdge(int from, int to) {
    Vertex* fromVertex = findVertex(from);
    Vertex* toVertex = findVertex(to);
    
    if (fromVertex == nullptr) {
        fromVertex = new Vertex(from);
        vertices.AddItem(fromVertex);
    }
    if (toVertex == nullptr) {
        toVertex = new Vertex(to);
        vertices.AddItem(toVertex);
    }

    fromVertex->outgoingEdges.AddItem(toVertex);
    toVertex->incomingEdges.AddItem(fromVertex);
}

// removes the edge if it exists, otherwise does nothing
void Graph::removeEdge(int from, int to) {
    Vertex* fromVertex = findVertex(from);

    if (fromVertex == nullptr) {
        return;
    }
    
    Vertex toRemove(to);
    Vertex* toVertex = fromVertex->outgoingEdges.Remove(&toRemove);
    if (toVertex == nullptr) {
        return;
    }
    fromVertex = toVertex->incomingEdges.Remove(fromVertex);

    // if vertex has no more edges, delete that sucker
    if (fromVertex->outgoingEdges.IsEmpty() && fromVertex->incomingEdges.IsEmpty()) {
        delete vertices.Remove(fromVertex);
    }
    if (toVertex->outgoingEdges.IsEmpty() && toVertex->incomingEdges.IsEmpty()) {
        delete vertices.Remove(toVertex);
    }
}

// determines whether an edge exists
bool Graph::hasEdge(int from, int to) {
    Vertex* fromVertex = findVertex(from);
    Vertex toVertex(to);
    return (fromVertex != nullptr && fromVertex->outgoingEdges.IsInList(&toVertex));
}

// returns pointer to list of edges originating from the node passed in
List<Vertex>* Graph::outEdges(int from) {
    Vertex* fromVertex = findVertex(from);
    if (fromVertex == nullptr) {
        return nullptr;
    }
    return &fromVertex->outgoingEdges;
}

// returns pointer to list of edges ending at the node passed in
List<Vertex>* Graph::inEdges(int to) {
    Vertex* toVertex = findVertex(to);
    if (toVertex == nullptr) {
        return nullptr;
    }
    return &toVertex->incomingEdges;
}

void Graph::depthFirstSearch() {
    if (vertices.IsEmpty()) {
        return;
    }

    Vertex* current = vertices.seeAt(0);
    if (current != nullptr) {
        resetVistedFlags();
        depthFirstSearch(current);
    }
}

void Graph::depthFirstSearch(Vertex* vertex) {
    vertex->visited = true;
    cout << vertex->data << endl;
    vertex->outgoingEdges.Reset();
    Vertex* outgoing = vertex->outgoingEdges.SeeNext();
    while (outgoing != nullptr) {
        if (outgoing->visited == false) {
            depthFirstSearch(outgoing);
        }
        outgoing = vertex->outgoingEdges.SeeNext();
    }
}

void Graph::breadthFirstSearch() {
    if (vertices.IsEmpty()) {
        return;
    }
    resetVistedFlags();
    
    List<Vertex> queue;
    Vertex* current = vertices.seeAt(0);
    queue.AddItem(current);

    while (!queue.IsEmpty()) {
        current = queue.RemoveFront();
        cout << current->data << endl;

        current->outgoingEdges.Reset();
        Vertex* child = current->outgoingEdges.SeeNext();
        while (child != nullptr) {
            if (!child->visited) {
                queue.AddItem(child);
                child->visited = true;
            }
            child = current->outgoingEdges.SeeNext();
        }
    }
}

void Graph::resetVistedFlags() {
    vertices.Reset();
    Vertex* current = vertices.SeeNext();
    while (current != nullptr) {
        current->visited = false;
        current = vertices.SeeNext();
    }
}

// time to clean this mess up
Graph::~Graph() {
    if (vertices.IsEmpty()) {
        return;
    }
    
    // go through vertices and delete them
    // this will delete the linked lists, which won't touch the vertices, preventing a double delete
    vertices.Reset();
    Vertex* vertex = vertices.SeeNext();
    while (vertex != nullptr) {
        delete vertex;
        vertex = vertices.SeeNext();
    }
}
