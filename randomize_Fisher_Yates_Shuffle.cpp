#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

using namespace std;

int main()
{
    int n;
    cout << "Enter number of students (n): ";
    cin >> n;

    // Dynamic memory allocation
    int *arr = new int[n];

    // Fill roll numbers from 1 to n
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // Seed random generator
    srand(time(0));

    // Fisher-Yates Shuffle
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);   // random index from 0 to i

        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Print randomized roll numbers
    cout << "Randomized Roll Numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Free memory
    delete[] arr;

    return 0;
}
