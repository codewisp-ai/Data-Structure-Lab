#include <iostream>
#include "graph.h"
using namespace std;

Node::Node(int val) {
    data = val;
    next = NULL;
}


Graph::Graph(int v) {
    V = v;
    adj = new Node*[V];

    for (int i = 0; i < V; i++)
        adj[i] = NULL;
}


void Graph::addEdge(int u, int v) {
    Node* newNode = new Node(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = new Node(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}


void Graph::printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << " : ";
        Node* temp = adj[i];
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// DFS for cycle detection and printing
bool Graph::dfsCycle(int v, bool visited[], int parent, int path[], int &idx) {
    visited[v] = true;
    path[idx++] = v;

    Node* temp = adj[v];

    while (temp) {
        int u = temp->data;

        if (!visited[u]) {
            if (dfsCycle(u, visited, v, path, idx))
                return true;
        }
        else if (u != parent) {
            // Cycle found — print cycle
            cout << "Cycle found: ";
            int start = u;

            int i = idx - 1;
            cout << start << " ";

            while (i >= 0 && path[i] != start) {
                cout << path[i] << " ";
                i--;
            }
            cout << start << endl;

            return true;
        }

        temp = temp->next;
    }

    idx--; // backtrack
    return false;
}

// Detect cycle
bool Graph::detectCycle() {
    bool* visited = new bool[V];
    int* path = new int[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            int idx = 0;
            if (dfsCycle(i, visited, -1, path, idx))
                return true;
        }
    }

    cout << "No cycle found\n";
    return false;
}