#include <limits.h>
#include <stdio.h>

int coinChange(int *coins, int coinsSize, int amount) {
    int dp[10001];
    for (int i = 1; i <= amount; ++i) dp[i] = INT_MAX / 2;
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) dp[i] = dp[i - coins[j]] + 1;
        }
    }
    return dp[amount] >= INT_MAX / 2 ? -1 : dp[amount];
}

int main(void) {
    int coins[] = {1, 2, 5};
    printf("%d\n", coinChange(coins, 3, 11));
    return 0;
}
