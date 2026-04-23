#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < (int)coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> c1 = {1, 2, 5};
    vector<int> c2 = {2};
    vector<int> c3 = {1};
    vector<int> c4 = {1, 2, 5};
    vector<int> c5 = {3, 7};
    cout << minCoinChange(c1, 11) << "\n";
    cout << minCoinChange(c2, 3) << "\n";
    cout << minCoinChange(c3, 0) << "\n";
    cout << minCoinChange(c4, 100) << "\n";
    cout << minCoinChange(c5, 4) << "\n";
    return 0;
}
