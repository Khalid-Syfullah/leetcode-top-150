#include <stdio.h>

int uniquePathsWithObstacles(int grid[3][3], int rows, int cols) {
    int dp[3] = {0};
    dp[0] = grid[0][0] == 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 1) dp[c] = 0;
            else if (c > 0) dp[c] += dp[c - 1];
        }
    }
    return dp[cols - 1];
}

int main(void) {
    int grid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    printf("%d\n", uniquePathsWithObstacles(grid, 3, 3));
    return 0;
}
