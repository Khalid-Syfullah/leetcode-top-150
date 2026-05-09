#include <stdio.h>

#define MAXN 101

int uniquePathsWithObstacles(int obstacleGrid[][MAXN], int m, int n) {
    int dp[MAXN][MAXN];

    /* Initialize entire dp to 0 */
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for (int i = 1; i < m; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int j = 1; j < n; j++) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main(void) {
    /* Test 1: obstacle in the middle */
    int grid1[MAXN][MAXN] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    printf("%d\n", uniquePathsWithObstacles(grid1, 3, 3)); /* 2 */

    /* Test 2: obstacle blocks path */
    int grid2[MAXN][MAXN] = {{0, 1}, {0, 0}};
    printf("%d\n", uniquePathsWithObstacles(grid2, 2, 2)); /* 1 */

    /* Test 3: single cell, no obstacle */
    int grid3[MAXN][MAXN] = {{0}};
    printf("%d\n", uniquePathsWithObstacles(grid3, 1, 1)); /* 1 */

    /* Test 4: single cell, is obstacle */
    int grid4[MAXN][MAXN] = {{1}};
    printf("%d\n", uniquePathsWithObstacles(grid4, 1, 1)); /* 0 */

    return 0;
}
