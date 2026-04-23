#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxSide = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int main() {
    vector<vector<char>> m1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    vector<vector<char>> m2 = {{'0','1'},{'1','0'}};
    vector<vector<char>> m3 = {{'0'}};
    vector<vector<char>> m4 = {{'0','1'}};
    cout << maximalSquare(m1) << "\n";
    cout << maximalSquare(m2) << "\n";
    cout << maximalSquare(m3) << "\n";
    cout << maximalSquare(m4) << "\n";
    return 0;
}
