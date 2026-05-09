#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int k, int *prices, int n) {
    if (k == 0 || n == 0) return 0;

    /* If k >= n/2, we can do unlimited transactions */
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    /* dp[i][j] = max profit using at most i transactions up to day j */
    int **dp = (int **)calloc(k + 1, sizeof(int *));
    for (int i = 0; i <= k; i++) {
        dp[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 1; i <= k; i++) {
        int localMax = -prices[0];

        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (localMax + prices[j] > dp[i][j]) dp[i][j] = localMax + prices[j];
            if (dp[i - 1][j] - prices[j] > localMax) localMax = dp[i - 1][j] - prices[j];
        }
    }

    int result = dp[k][n - 1];
    for (int i = 0; i <= k; i++) free(dp[i]);
    free(dp);
    return result;
}

int main(void) {
    int a[] = {2, 4, 1};
    printf("%d\n", maxProfit(2, a, 3)); /* 2 */

    int b[] = {3, 2, 6, 5, 0, 3};
    printf("%d\n", maxProfit(2, b, 6)); /* 7 */

    int c[] = {1, 2, 3, 4, 5};
    printf("%d\n", maxProfit(2, c, 5)); /* 4 */

    int d[] = {7, 6, 4, 3, 1};
    printf("%d\n", maxProfit(2, d, 5)); /* 0 */

    return 0;
}
