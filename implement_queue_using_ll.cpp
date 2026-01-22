#include <iostream>
using namespace std;

/* ================= NODE CLASS ================= */
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/* ================= LINKED LIST CLASS ================= */
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Add value at given position (0-based)
    void add(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 0 || head == NULL) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Remove first occurrence of value
    void remove(int value) {
        if (head == NULL) return;

        if (head->data == value) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    // Create list by taking n user inputs
    void create(int n) {
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            add(x, i);
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ONLY helper allowed to support Queue
    int getHeadValue() {
        if (head == NULL) return -1;
        return head->data;
    }
};

/* ================= QUEUE CLASS ================= */
class Queue {
private:
    LinkedList list;
    int size;

public:
    Queue() {
        size = 0;
    }

    // Enqueue → insert at end using LinkedList add
    void enqueue(int value) {
        list.add(value, size);
        size++;
    }

    // Dequeue → remove front element automatically
    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        int frontValue = list.getHeadValue();
        list.remove(frontValue);
        size--;
    }

    // Create queue using LinkedList create
    void create(int n) {
        size = n;
        list.create(n);
    }

    // Display queue
    void display() {
        list.display();
    }
};

/* ================= MAIN ================= */
int main() {
    Queue q;

    cout << "Create queue (enter 5 elements):\n";
    q.create(5);

    cout << "Queue: ";
    q.display();

    q.enqueue(100);
    cout << "After enqueue 100: ";
    q.display();

    q.dequeue();
    cout << "After dequeue: ";
    q.display();

    q.dequeue();
    cout << "After dequeue: ";
    q.display();

    return 0;
}
