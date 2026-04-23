#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy1 = INT_MIN;
    int sell1 = 0;
    int buy2 = INT_MIN;
    int sell2 = 0;
    for (int p : prices) {
        buy1  = max(buy1,  -p);
        sell1 = max(sell1, buy1 + p);
        buy2  = max(buy2,  sell1 - p);
        sell2 = max(sell2, buy2 + p);
    }
    return sell2;
}

int main() {
    vector<int> p1 = {3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> p2 = {1, 2, 3, 4, 5};
    vector<int> p3 = {7, 6, 4, 3, 1};
    cout << maxProfit(p1) << "\n";
    cout << maxProfit(p2) << "\n";
    cout << maxProfit(p3) << "\n";
    return 0;
}
