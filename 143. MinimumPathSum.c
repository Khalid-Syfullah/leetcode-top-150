#include <stdio.h>

int minPathSum(int grid[3][3], int rows, int cols) {
    int dp[3][3];
    dp[0][0] = grid[0][0];
    for (int r = 1; r < rows; ++r) dp[r][0] = dp[r - 1][0] + grid[r][0];
    for (int c = 1; c < cols; ++c) dp[0][c] = dp[0][c - 1] + grid[0][c];
    for (int r = 1; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
            dp[r][c] = (dp[r - 1][c] < dp[r][c - 1] ? dp[r - 1][c] : dp[r][c - 1]) + grid[r][c];
        }
    }
    return dp[rows - 1][cols - 1];
}

int main(void) {
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    printf("%d\n", minPathSum(grid, 3, 3));
    return 0;
}
