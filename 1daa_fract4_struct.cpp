#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit;
    int weight;
    float pw; // Profit-to-weight ratio
};

void printTable(const vector<Item>& items) {
    cout << "Profit Weight P/W" << endl;
    for (const auto& item : items) {
        cout << fixed << setprecision(2) //only 2 decimal tak print karne ke liye
             << item.profit << "    "
             << item.weight << "    "
             << item.pw << endl;
    }
    cout << endl;
}

void takeInput(vector<Item>& items, int& n, float& maxWeight) {
    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> profit;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> weight;
        cout << endl;
        
        float pw = static_cast<float>(profit) / weight; //type casting to float //profit-to-weight ratio
        items.push_back({profit, weight, pw});
    }

    cout << "Enter maximum weight allowed: ";
    cin >> maxWeight;
    cout << endl;
}

int main() {
    vector<Item> items;
    int n;
    float maxWeight;
    takeInput(items, n, maxWeight);

    cout << "Entered Elements are:\n";
    printTable(items);

    // Sort items in descending order of profit-to-weight ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.pw > b.pw;
    });

    float totalProfit = 0;

    for (const auto& item : items) {
        if (item.weight <= maxWeight) {
            maxWeight -= item.weight;
            totalProfit += item.profit;
        } else {
            float fraction = maxWeight / item.weight;
            totalProfit += item.profit * fraction;
            break; // Knapsack is full
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
    return 0;
}
