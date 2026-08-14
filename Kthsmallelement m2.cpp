#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    sort(a, a + n);

    cout << "Kth smallest element = " << a[k - 1];

    return 0;
}
