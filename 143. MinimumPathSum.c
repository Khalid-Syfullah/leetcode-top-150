#include <stdio.h>

#define MAXN 200

int minPathSum(int grid[][MAXN], int m, int n) {
    int dp[MAXN][MAXN];

    dp[0][0] = grid[0][0];

    /* Fill first column (can only come from above) */
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    /* Fill first row (can only come from the left) */
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    /* Fill the rest of the DP table */
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int fromAbove = dp[i - 1][j];
            int fromLeft  = dp[i][j - 1];
            dp[i][j] = grid[i][j] + (fromAbove < fromLeft ? fromAbove : fromLeft);
        }
    }

    return dp[m - 1][n - 1];
}

int main(void) {
    int grid1[MAXN][MAXN] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    printf("Example 1: %d\n", minPathSum(grid1, 3, 3)); /* 7 */

    int grid2[MAXN][MAXN] = {{1, 2, 3}, {4, 5, 6}};
    printf("Example 2: %d\n", minPathSum(grid2, 2, 3)); /* 12 */

    return 0;
}
