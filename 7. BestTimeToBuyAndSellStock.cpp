#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int mn = INT_MAX, best = 0;
    for (int p : prices) {
        if (p < mn) mn = p;
        else if (p - mn > best) best = p - mn;
    }
    return best;
}

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(a) << "\n";

    vector<int> b = {7, 6, 4, 3, 1};
    cout << maxProfit(b) << "\n";

    vector<int> c = {2, 4, 1};
    cout << maxProfit(c) << "\n";

    return 0;
}
