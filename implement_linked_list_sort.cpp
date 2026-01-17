// Implement Link List and sort it by any function

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // bubble sort
    void sort()
    {
        if (head == NULL)
            return;

        for (Node *i = head; i != NULL; i = i->next)
        {
            for (Node *j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};

int main()
{
    LinkedList list;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        list.insert(x);
    }

    cout << "\nBefore Sorting:\n";
    list.print();

    list.sort();

    cout << "\nAfter Sorting:\n";
    list.print();

    return 0;
}
