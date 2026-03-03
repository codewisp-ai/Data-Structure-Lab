#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Structure-only similarity check
bool similar(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    return similar(root1->left, root2->left) &&
           similar(root1->right, root2->right);
}

// Function to build tree from file
Node* buildTree(const string &filename)
{
    fstream file;
    file.open(filename, ios::in);

    if (!file)
    {
        cout << "Error opening file: " << filename << endl;
        return nullptr;
    }

    string word;
    Node *root = nullptr;

    while (file >> word)
    {
        // First line (root value)
        if (word[0] != 'L' && word[0] != 'R')
        {
            int value = stoi(word);
            root = new Node(value);
        }
        else
        {
            int i = 0;
            string path = "";

            // Extract path (L and R)
            while (i < word.length() && (word[i] == 'L' || word[i] == 'R'))
            {
                path += word[i];
                i++;
            }

            // Extract value
            int value = stoi(word.substr(i));

            Node *temp = root;

            for (int j = 0; j < path.length(); j++)
            {
                if (path[j] == 'L')
                {
                    if (temp->left == nullptr)
                        temp->left = new Node(0);

                    if (j == path.length() - 1)
                        temp->left->data = value;

                    temp = temp->left;
                }
                else if (path[j] == 'R')
                {
                    if (temp->right == nullptr)
                        temp->right = new Node(0);

                    if (j == path.length() - 1)
                        temp->right->data = value;

                    temp = temp->right;
                }
            }
        }
    }

    file.close();
    return root;
}

int main()
{
    Node *root1 = buildTree("tree1.txt");
    Node *root2 = buildTree("tree2.txt");

    if (similar(root1, root2))
        cout << "Trees are structurally similar" << endl;
    else
        cout << "Trees are NOT structurally similar" << endl;

    return 0;
}