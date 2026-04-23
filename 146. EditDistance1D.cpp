#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = (int)word1.size();
    int n = (int)word2.size();
    vector<int> dp(n + 1);
    for (int j = 0; j <= n; j++) {
        dp[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        int prev = i - 1;
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min(prev, min(temp, dp[j - 1]));
            }
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    cout << minDistance("horse", "ros") << "\n";
    cout << minDistance("intention", "execution") << "\n";
    cout << minDistance("", "a") << "\n";
    cout << minDistance("a", "a") << "\n";
    cout << minDistance("abc", "def") << "\n";
    return 0;
}
