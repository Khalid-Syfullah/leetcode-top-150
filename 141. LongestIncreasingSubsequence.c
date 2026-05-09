#include <stdio.h>

int lengthOfLIS(int *nums, int n) {
    if (n == 0) return 0;

    int dp[2501];
    for (int i = 0; i < n; i++) dp[i] = 1;
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                int candidate = dp[j] + 1;
                if (candidate > dp[i]) dp[i] = candidate;
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    return maxLen;
}

int main(void) {
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("%d\n", lengthOfLIS(a, 8)); /* 4 */

    int b[] = {0, 1, 0, 3, 2, 3};
    printf("%d\n", lengthOfLIS(b, 6)); /* 4 */

    int c[] = {7, 7, 7, 7, 7, 7, 7};
    printf("%d\n", lengthOfLIS(c, 7)); /* 1 */

    int d[] = {1};
    printf("%d\n", lengthOfLIS(d, 1)); /* 1 */

    return 0;
}
