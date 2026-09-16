#include <iostream>
using namespace std;

#define SIZE 10

int main() {
    int table[SIZE];

    // Initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";

    for (int i = 0; i < n; i++) {
        cin >> key;

        int h = key % SIZE;
        bool inserted = false;

        // Quadratic probing
        for (int j = 0; j < SIZE; j++) {
            int index = (h + j * j) % SIZE;

            if (table[index] == -1) {
                table[index] = key;
                inserted = true;
                break;
            }
        }

        if (!inserted)
            cout << "Cannot insert " << key << endl;
    }

    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> " << table[i] << endl;
    }

    return 0;
}
