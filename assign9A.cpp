// A. Given a set of items with weights and values, and a knapsack capacity, find the maximum total
// value that can be obtained by selecting fractions of items using the Greedy strategy.


#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(Item items[], int n, int capacity) {

    sort(items, items + n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; ++i) {
        if (capacity >= items[i].weight) 
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else 
        {

            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    Item* items = new Item[n];

    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, n, capacity);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    delete[] items;
    return 0;
}
