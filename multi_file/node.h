#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
public:
    float data;
    Node* left;
    Node* right;

    Node(float val);
};

// BST functions
Node* insert(Node* root, float val);
void inorder(Node* root);

#endif
