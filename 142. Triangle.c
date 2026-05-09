#include <stdio.h>
#include <limits.h>

/* Represent the triangle as a flat array with row lengths 1, 2, ..., n.
   Element at row r, column c is at index r*(r+1)/2 + c. */
static int minimumTotal(int *flat, int n) {
    if (n == 0) return 0;

    /* dp holds the bottom row initially */
    int dp[201];
    int offset = n * (n - 1) / 2; /* start index of last row */
    for (int c = 0; c < n; c++) dp[c] = flat[offset + c];

    /* Work upward */
    for (int r = n - 2; r >= 0; r--) {
        int rowOffset = r * (r + 1) / 2;
        for (int c = 0; c <= r; c++) {
            int minChild = dp[c] < dp[c + 1] ? dp[c] : dp[c + 1];
            dp[c] = flat[rowOffset + c] + minChild;
        }
    }

    return dp[0];
}

int main(void) {
    /* Test case 1: [[2],[3,4],[6,5,7],[4,1,8,3]] => 11 */
    int t1[] = {2, 3, 4, 6, 5, 7, 4, 1, 8, 3};
    printf("%d\n", minimumTotal(t1, 4)); /* 11 */

    /* Test case 2: [[-10]] => -10 */
    int t2[] = {-10};
    printf("%d\n", minimumTotal(t2, 1)); /* -10 */

    /* Test case 3: [[1],[2,3]] => 3 */
    int t3[] = {1, 2, 3};
    printf("%d\n", minimumTotal(t3, 2)); /* 3 */

    return 0;
}
