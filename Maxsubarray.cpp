#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = -1000000;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = -1000000;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left = maxSubarraySum(arr, low, mid);
    int right = maxSubarraySum(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max(left, max(right, cross));
}

int main() {
    int n, arr[100];

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum: " << ans << endl;

    return 0;
}
