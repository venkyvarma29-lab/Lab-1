#include <iostream>
using namespace std;

struct Result {
    int minimum;
    int maximum;
};

Result findMinMax(int arr[], int low, int high) {
    Result r;

    // Only one element
    if (low == high) {
        r.minimum = arr[low];
        r.maximum = arr[low];
        return r;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            r.minimum = arr[low];
            r.maximum = arr[high];
        } else {
            r.minimum = arr[high];
            r.maximum = arr[low];
        }
        return r;
    }

    int mid = (low + high) / 2;

    Result left = findMinMax(arr, low, mid);
    Result right = findMinMax(arr, mid + 1, high);

    r.minimum = min(left.minimum, right.minimum);
    r.maximum = max(left.maximum, right.maximum);

    return r;
}

int main() {
    int n, arr[100];

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Result ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << ans.minimum << endl;
    cout << "Maximum element: " << ans.maximum << endl;

    return 0;
}
