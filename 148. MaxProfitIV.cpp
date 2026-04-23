#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = (int)prices.size();
    if (k == 0 || n == 0) return 0;
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i <= k; i++) {
        int localMax = -prices[0];
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], localMax + prices[j]);
            localMax = max(localMax, dp[i - 1][j] - prices[j]);
        }
    }
    return dp[k][n - 1];
}

int main() {
    vector<int> prices1 = {2, 4, 1};
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    vector<int> prices3 = {1, 2, 3, 4, 5};
    vector<int> prices4 = {7, 6, 4, 3, 1};
    cout << maxProfit(2, prices1) << "\n";
    cout << maxProfit(2, prices2) << "\n";
    cout << maxProfit(2, prices3) << "\n";
    cout << maxProfit(2, prices4) << "\n";
    return 0;
}
