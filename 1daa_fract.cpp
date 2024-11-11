// Practical 1A - Fractional Knapsack Using Greedy Algorithm

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void printTable(const vector<vector<float>> &items, bool isResult)
{
    const int cellWidth = 10;
    cout << setw(cellWidth) << left << "Profit     |";
    cout << setw(cellWidth) << left << "Weight     |";
    if (isResult)
        cout << setw(cellWidth) << left << "Fraction    |";
    else
        cout << setw(cellWidth) << left << "P/W        |";
    cout << endl;

    for (int i = 0; i < 3; ++i)
        cout << "+----------+";
    cout << endl;

    for (const auto &item : items)
    {
        cout << setfill(' ') << setw(cellWidth) << left << item[1] << " |";
        cout << setw(cellWidth) << left << item[2] << " |";
        cout << setw(cellWidth) << left << item[0] << " |";
        cout << endl;
    }
    cout << endl;
}

void takeInput(vector<vector<float>> &items, int &n, float &maxWeight)
{
    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        float profit, itemWeight, pw;
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> profit;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> itemWeight;
        cout << endl;

        pw = profit / itemWeight;
        items.push_back({pw, profit, itemWeight});
    }

    cout << "Enter maximum weight allowed: ";
    cin >> maxWeight;
    cout << endl;
}

int main()
{
    vector<vector<float>> items;
    int n;
    float maxWeight;
    takeInput(items, n, maxWeight);

    cout << "Entered Elements are:" << endl;
    printTable(items, false);

    sort(items.rbegin(), items.rend()); // Sort in descending order of P/W

    vector<vector<float>> result = items;
    float totalProfit = 0;

    for (auto &item : result)
    {
        if (item[2] <= maxWeight)
        {
            maxWeight -= item[2];
            totalProfit += item[1];
            item[0] = 1; // Full item taken
        }
        else
        {
            totalProfit += item[1] * (maxWeight / item[2]);
            item[0] = (maxWeight / item[2]); // Fraction taken
            break;
        }
    }

    cout << "Final Result:" << endl;
    printTable(result, true);

    cout << "Total Profit: " << totalProfit << endl;
}
// printing in increasing order which is wrong