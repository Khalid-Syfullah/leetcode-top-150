#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    vector<int> v1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> v2 = {0, 1, 0, 3, 2, 3};
    vector<int> v3 = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(v1) << "\n";
    cout << lengthOfLIS(v2) << "\n";
    cout << lengthOfLIS(v3) << "\n";
    return 0;
}
