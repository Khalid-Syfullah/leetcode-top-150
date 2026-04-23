#include <stdio.h>

int minimumTotal(int triangle[4][4], int rows) {
    int dp[4];
    for (int c = 0; c < rows; ++c) dp[c] = triangle[rows - 1][c];
    for (int r = rows - 2; r >= 0; --r) {
        for (int c = 0; c <= r; ++c) {
            dp[c] = triangle[r][c] + (dp[c] < dp[c + 1] ? dp[c] : dp[c + 1]);
        }
    }
    return dp[0];
}

int main(void) {
    int triangle[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    printf("%d\n", minimumTotal(triangle, 4));
    return 0;
}
