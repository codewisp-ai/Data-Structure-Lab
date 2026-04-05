#include <iostream>
#include <fstream>
#include <climits>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insertNode(Node* root, string path, int value) {
    if (root == NULL) return NULL;

    Node* curr = root;

   
    for (int i = 0; i < path.length() - 1; i++) {
        if (path[i] == 'L') {
            if (curr->left == NULL)
                curr->left = new Node(0); // temporary node
            curr = curr->left;
        } else {
            if (curr->right == NULL)
                curr->right = new Node(0);
            curr = curr->right;
        }
    }

    if (path[path.length() - 1] == 'L') {
        curr->left = new Node(value);
    } else {
        curr->right = new Node(value);
    }

    return root;
}

// Function to check BST using range method
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    ifstream file("a.txt");

    int rootVal;
    file >> rootVal;

    Node* root = new Node(rootVal);

    string str;

    while (file >> str) {
        int i = 0;

        
        while (str[i] == 'L' || str[i] == 'R') i++;

        string path = str.substr(0, i);
        int value = stoi(str.substr(i));

        root = insertNode(root, path, value);
    }

    file.close();

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "Tree is a BST" << endl;
    else
        cout << "Tree is NOT a BST" << endl;

    return 0;
}