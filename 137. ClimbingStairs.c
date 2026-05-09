#include <stdio.h>

int climbStairs(int n) {
    if (n <= 1) {
        return 1;
    }

    /* dp[i] represents the number of ways to reach step i */
    int dp[46]; /* n is at most 45 per LeetCode constraints */
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(void) {
    printf("%d\n", climbStairs(2));  /* 2 */
    printf("%d\n", climbStairs(3));  /* 3 */
    printf("%d\n", climbStairs(4));  /* 5 */
    printf("%d\n", climbStairs(5));  /* 8 */
    printf("%d\n", climbStairs(9));  /* 55 */
    printf("%d\n", climbStairs(10)); /* 89 */
    return 0;
}
