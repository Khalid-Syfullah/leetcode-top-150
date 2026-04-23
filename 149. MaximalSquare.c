#include <stdio.h>

int maximalSquare(char matrix[4][6], int rows, int cols) {
    int dp[6] = {0};
    int best = 0;
    for (int r = 1; r <= rows; ++r) {
        int prev = 0;
        for (int c = 1; c <= cols; ++c) {
            int temp = dp[c];
            if (matrix[r - 1][c - 1] == '1') {
                int min = dp[c] < dp[c - 1] ? dp[c] : dp[c - 1];
                if (prev < min) min = prev;
                dp[c] = min + 1;
                if (dp[c] > best) best = dp[c];
            } else {
                dp[c] = 0;
            }
            prev = temp;
        }
    }
    return best * best;
}

int main(void) {
    char matrix[4][6] = {"10100", "10111", "11111", "10010"};
    printf("%d\n", maximalSquare(matrix, 4, 5));
    return 0;
}
