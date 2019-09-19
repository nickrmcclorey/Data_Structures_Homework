#include <iostream>
#include "Graph.h"
#include <string>
using namespace std;

void print(List<Vertex>* list) {
    list->Reset();
    Vertex* vertex = list->SeeNext();
    cout << "[ ";
    while (vertex != nullptr) {
        cout << vertex->data << ", ";
        vertex = list->SeeNext();
    }
    cout << "]\n";
}

void TestGraph(){
    Graph g1;
    string userIn;
    do{
        cout << "Press 1 to add an edge to the graph" << endl;
        cout << "Press 2 to remove an edge from the graph" << endl;
        cout << "Press 3 to find an edge in the graph" << endl;
        cout << "Press 4 to find the out edges of a vertex" << endl;
        cout << "Press 5 to find the in edges of a vertex" << endl;
        cout << "Press 6 to do a depth first search" << endl;
        cout << "Press 7 to do a breadth first search" << endl;
        cout << "Press 8 to quit" << endl;
        cin >> userIn;
        if(userIn == "1"){
            cout << "Enter the two vertices to connect starting with the originating vertex" << endl;
            int from, to;
            cin >> from;
            cin >> to;
            g1.addEdge(from, to);
        }
        else if(userIn == "2"){
            cout << "Enter the two vertices to disconnect starting with the originating vertex" << endl;
            int from, to;
            cin >> from;
            cin >> to;
            g1.removeEdge(from, to);
            cout << "The vertices have been disconnected" << endl;
        }
        else if(userIn == "3"){
            cout << "Enter the vertex to find starting with the originating vertex" << endl;
            int from, to;
            cin >> from;
            cin >> to;
            if (g1.hasEdge(from, to)) {
                cout << "Edge from " << from << " to " << to << " exists" << endl;
            } else {
                cout << "Edge from " << from << " to " << to << " doesn't exist" << endl;
            }
        }
        else if(userIn == "4"){
            cout << "Enter the vertex" << endl;
            int from;
            cin >> from;
            List<Vertex>* list = g1.outEdges(from);
            if (list == nullptr) {
                cout << "Vertex wasn't found" << endl << endl;
            } else {
                print(list);
            }
        }
        else if(userIn == "5"){
            cout << "Enter the vertex" << endl;
            int to;
            cin >> to;
            List<Vertex>* list = g1.inEdges(to);
            if (list == nullptr) {
                cout << "Vertex wasn't found" << endl << endl;
            } else {
                print(list);
            }
        }
        else if (userIn == "6"){
            cout << "Depth First Search:" << endl;
            g1.depthFirstSearch();
        }
        else if (userIn == "7"){
            cout << "Breadth First Search:" << endl;
            g1.breadthFirstSearch();
        }
        else if(userIn == "8"){
            cout << "Exiting." << endl;
        }
        else{
            cout << "Invalid choice. Try Again." << endl;
        }
    }
    while(userIn != "8");
}

void testingGround() {
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.removeEdge(2, 3);
    if (graph.hasEdge(1, 2)) {
        cout << "cool" << endl;
    }
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 7);
    graph.addEdge(2, 7);
    graph.addEdge(1, 6);
    graph.addEdge(6, 7);
    graph.breadthFirstSearch();
    graph.depthFirstSearch();
}

int main(){
    TestGraph();
    cout << "no runtime errors" << endl;
    return 0;
}