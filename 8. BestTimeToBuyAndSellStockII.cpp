#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a) << "\n";

    vector<int> b = {1, 2, 3, 4, 5};
    cout << maxProfit(b) << "\n";

    vector<int> c = {7, 6, 4, 3, 1};
    cout << maxProfit(c) << "\n";

    return 0;
}
