#include <stdio.h>
#include <iostream>

using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio;
    Item() : profit(0), weight(0) {};
    Item(int p, int w) : profit(p), weight(w) {};
};

void print(Item items[], int n) {
    for(int i = 0; i < n; i++) {
        cout << items[i].ratio << " ";
    }
}

bool compareRatio(Item i1, Item i2)
{
    return (i1.ratio > i2.ratio);
}

double solveGreedy(Item items[], int n, int w) {
    double result = 0.0;
    for(int i = 0; i < n; i++) {
        Item item = items[i];
        item.ratio = (double) item.profit / item.weight;
        items[i] = item;
    }
    sort(items, items + n, compareRatio);
    print(items, n);
    for(int j = 0; j < n; j++) {
        if(w - items[j].weight < 0) {
            result += w * items[j].ratio;
            break;
        }
        else {
            result += items[j].profit;
            w -= items[j].weight;
        }
    }
    return result;
}

int main() {
    int n = 3;
    Item items[n];
    items[0].profit = 500;
    items[0].weight = 30;
    items[1].profit = 100;
    items[1].weight = 20;
    items[2].profit = 120;
    items[2].weight = 30;
    double solution = solveGreedy(items, n, 50);
    cout << "solution: " << solution;
}