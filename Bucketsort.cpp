#include <iostream>
using namespace std;

int main() {
    int n, arr[100];

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter non-negative array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxValue = arr[0];

    // Find maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    // Create buckets
    int bucket[1000] = {0};

    // Count elements
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Reconstruct sorted array
    int k = 0;
    for (int i = 0; i <= maxValue; i++) {
        while (bucket[i] > 0) {
            arr[k++] = i;
            bucket[i]--;
        }
    }

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
