// only '()' allowed

#include <iostream>
using namespace std;

// Stack class
class Stack {
private:
    char *arr;
    int top;
    int size;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new char[size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool push(char x) {
        if (top == size - 1)
            return false;
        top++;
        arr[top] = x;
        return true;
    }

    bool pop() {
        if (top == -1)
            return false;
        top--;
        return true;
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    int n;
    cout << "Enter number of parentheses: ";
    cin >> n;

    char *str = new char[n + 1];
    cout << "Enter parentheses string: ";
    cin >> str;

    Stack s(n);

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            s.push('(');
        }
        else if (str[i] == ')') {
            if (!s.pop()) {
                cout << "Invalid Parentheses\n";
                delete[] str;
                return 0;
            }
        }
    }

    if (s.isEmpty())
        cout << "Valid Parentheses\n";
    else
        cout << "Invalid Parentheses\n";

    delete[] str;
    return 0;
}
