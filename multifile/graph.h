#ifndef GRAPH_H
#define GRAPH_H

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

class Graph {
public:
    int V;
    Node** adj;  

    Graph(int v);

    void addEdge(int u, int v);
    void printGraph();

    bool detectCycle();
    bool dfsCycle(int v, bool visited[], int parent, int path[], int &idx);
};

#endif