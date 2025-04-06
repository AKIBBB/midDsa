#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    int weight;
    int cost;
    double profitPerKg;
};

void calculateProfitPerKg(Item &item) {
    item.profitPerKg = (double)item.cost / item.weight;
}

void stealItems(vector<Item> &items, int knapsackCapacity) {
    int thiefCount = 0;

    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.profitPerKg > b.profitPerKg;
    });

    while (true) {
        int totalWeight = 0;
        int totalProfit = 0;
        vector<string> stolenItems;
        thiefCount++;

        for (auto &item : items) {
            if (item.weight <= knapsackCapacity - totalWeight) {
                stolenItems.push_back(item.name);
                totalWeight += item.weight;
                totalProfit += item.cost;
                item.weight = 0; 
            }

            if (totalWeight == knapsackCapacity) {
                break;
            }
        }

        cout << "Thief " << thiefCount << " steals: ";
        for (const auto &stolen : stolenItems) {
            cout << stolen << " ";
        }
        cout << "\nProfit: " << totalProfit << " taka\n";

        bool allStolen = true;
        for (const auto &item : items) {
            if (item.weight > 0) {
                allStolen = false;
                break;
            }
        }

        if (allStolen) {
            break;
        }
    }
}

int main() {
    vector<Item> items = {
        {"Rice", 12, 840, 0.0},  
        {"Salt", 10, 870, 0.0},  
        {"Saffron", 8, 2000, 0.0}, 
        {"Sugar", 5, 500, 0.0}    
    };

    for (auto &item : items) {
        calculateProfitPerKg(item);
    }

    int knapsackCapacity = 9;

    stealItems(items, knapsackCapacity);

    return 0;
}
