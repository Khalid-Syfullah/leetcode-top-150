#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isInterleave(const char *s1, const char *s2, const char *s3) {
    int m = (int)strlen(s1);
    int n = (int)strlen(s2);

    /* Step 1: Length check */
    if (m + n != (int)strlen(s3)) return false;

    /* Step 2: DP table */
    bool **dp = (bool **)malloc((m + 1) * sizeof(bool *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (bool *)calloc(n + 1, sizeof(bool));
    }

    /* Step 3: Base case */
    dp[0][0] = true;

    /* Step 4: Fill first column (using only s1) */
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    /* Step 5: Fill first row (using only s2) */
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
    }

    /* Step 6: Fill the rest */
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                       (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    bool result = dp[m][n];

    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);

    return result;
}

int main(void) {
    puts(isInterleave("aaa", "aaa", "aaaaaa") ? "true" : "false"); /* true */
    return 0;
}
