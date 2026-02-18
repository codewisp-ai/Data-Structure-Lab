#include <iostream>
#include <fstream>
#include "node.h"

using namespace std;

int main() {

    Node* root = NULL;
    ifstream fin;
    float value;

    fin.open("data.txt");

    if (!fin) {
        cout << "File not found\n";
        return 1;
    }

    // Read values from file
    while (fin >> value) {
        root = insert(root, value);
    }

    fin.close();

    cout << "Inorder Traversal:\n";
    inorder(root);

    return 0;
}
