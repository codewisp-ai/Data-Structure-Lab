#include <iostream>
#include <fstream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void insert(Node *root, string path, int val)
{
    Node *temp = root;
    int i;
    for (i = 0; i < path.length() - 1; i++)
    {
        if (path[i] == 'L')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (path[i] == 'L')
    {
        temp->left = new Node(val);
    }
    else
    {
        temp->right = new Node(val);
    }
}
void buildTree(Node *&root, string filename)
{
    fstream f;
    f.open(filename, ios::in);
    string s;
    while (f >> s)
    {
        if (s[0] != 'L' && s[0] != 'R')
        {
            root = new Node(stoi(s));
            continue;
        }

        string path = "";
        int val;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L' || s[i] == 'R')
            {
                path += s[i];
            }
            else
            {
                val = stoi(s.substr(i));
            }
        }
        insert(root, path, val);
    }
}

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool isSimilar(Node *root1, Node *root2)
{
    if (root2 == nullptr)
    {
        return true;
    }
    if (root1 == nullptr)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }

    return isSimilar(root1->left, root2->left) && isSimilar(root1->right, root2->right);
}

bool isSubtree(Node *root1, Node *root2)
{
    if (root1 == nullptr)
    {
        return false;
    }
    if (isSimilar(root1, root2))
    {
        return true;
    }
    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}
int main()
{
    Node *root1 = nullptr;
    Node *root2 = nullptr;

    buildTree(root1, "a.txt");   // main tree
    buildTree(root2, "b.txt");   // subtree

    cout << "Main Tree Inorder: ";
    inOrder(root1);
    cout << endl;

    cout << "Sub Tree Inorder: ";
    inOrder(root2);
    cout << endl;

    if(isSubtree(root1, root2))
        cout << "TRUE - Subtree can be placed over Main Tree";
    else
        cout << "FALSE - Subtree cannot be placed over Main Tree";
}