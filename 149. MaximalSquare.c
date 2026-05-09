#include <stdio.h>

int maximalSquare(char **matrix, int rows, int cols) {
    if (matrix == NULL || rows == 0 || cols == 0) return 0;

    /* Use (rows+1) x (cols+1) dp table with 1-based indexing */
    int dp[301][301];
    for (int i = 0; i <= rows; i++)
        for (int j = 0; j <= cols; j++)
            dp[i][j] = 0;

    int maxSide = 0;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];
                int m = a < b ? a : b;
                if (c < m) m = c;
                dp[i][j] = m + 1;
                if (dp[i][j] > maxSide) maxSide = dp[i][j];
            }
        }
    }

    return maxSide * maxSide;
}

int main(void) {
    /* Test 1: 4x5 matrix -> 4 */
    char *m1[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    printf("%d\n", maximalSquare(m1, 4, 5)); /* 4 */

    /* Test 2: 2x2 checkerboard -> 1 */
    char *m2[] = {"01", "10"};
    printf("%d\n", maximalSquare(m2, 2, 2)); /* 1 */

    /* Test 3: single '0' -> 0 */
    char *m3[] = {"0"};
    printf("%d\n", maximalSquare(m3, 1, 1)); /* 0 */

    /* Test 4: 1x2 row with '0','1' -> 1 */
    char *m4[] = {"01"};
    printf("%d\n", maximalSquare(m4, 1, 2)); /* 1 */

    return 0;
}
