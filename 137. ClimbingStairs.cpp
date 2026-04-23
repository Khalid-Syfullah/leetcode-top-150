#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << climbStairs(2) << "\n";
    cout << climbStairs(3) << "\n";
    cout << climbStairs(4) << "\n";
    cout << climbStairs(5) << "\n";
    cout << climbStairs(9) << "\n";
    cout << climbStairs(10) << "\n";
    return 0;
}
