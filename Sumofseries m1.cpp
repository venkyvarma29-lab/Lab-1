#include <iostream>
using namespace std;

int main() {
    int x, n;
    long long sum = 0;
    long long term = 1;

    cout << "Enter x and n: ";
    cin >> x >> n;

    for (int i = 0; i <= n; i++) {
        sum = sum + term;
        term = term * x;
    }

    cout << "Sum = " << sum;

    return 0;
}
