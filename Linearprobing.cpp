#include <iostream>
using namespace std;

#define SIZE 10

int main() {
    int table[SIZE];

    // Initialize table with -1
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";

    for (int i = 0; i < n; i++) {
        cin >> key;

        int index = key % SIZE;
        int start = index;

        // Linear probing
        while (table[index] != -1) {
            index = (index + 1) % SIZE;

            if (index == start) {
                cout << "Hash table is full!\n";
                break;
            }
        }

        if (table[index] == -1)
            table[index] = key;
    }

    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> " << table[i] << endl;
    }

    return 0;
}
