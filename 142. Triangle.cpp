#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    int n = (int)triangle.size();
    vector<int> dp(triangle[n - 1].begin(), triangle[n - 1].end());
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

int main() {
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> t2 = {{-10}};
    vector<vector<int>> t3 = {{1}, {2, 3}};
    cout << minimumTotal(t1) << "\n";
    cout << minimumTotal(t2) << "\n";
    cout << minimumTotal(t3) << "\n";
    return 0;
}
