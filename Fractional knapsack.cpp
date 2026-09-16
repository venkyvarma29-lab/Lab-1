#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    cout << "Enter profit and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by profit/weight ratio
    sort(items, items + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            // Take full item
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fraction of item
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}
