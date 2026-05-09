#include <stdio.h>
#include <stdlib.h>

int minCoinChange(int *coins, int coinsSize, int amount) {
    if (amount < 1) return 0;

    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++) dp[i] = amount + 1;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                int val = dp[i - coins[j]] + 1;
                if (val < dp[i]) dp[i] = val;
            }
        }
    }

    int result = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return result;
}

int main(void) {
    int a[] = {1, 2, 5};
    printf("%d\n", minCoinChange(a, 3, 11)); /* 3 */

    int b[] = {2};
    printf("%d\n", minCoinChange(b, 1, 3));  /* -1 */

    int c[] = {1};
    printf("%d\n", minCoinChange(c, 1, 0));  /* 0 */

    int d[] = {1, 2, 5};
    printf("%d\n", minCoinChange(d, 3, 100)); /* 20 */

    int e[] = {3, 7};
    printf("%d\n", minCoinChange(e, 2, 4));  /* -1 */

    return 0;
}
