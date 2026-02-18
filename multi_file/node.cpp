#include "node.h"

// Node constructor
Node::Node(float val) {
    data = val;
    left = NULL;
    right = NULL;
}

// Insert function
Node* insert(Node* root, float val) {

    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

