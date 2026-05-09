#include <stdio.h>
#include <string.h>

int minDistance(const char *word1, const char *word2) {
    int m = (int)strlen(word1);
    int n = (int)strlen(word2);

    /* dp[j] = edit distance between word1[0..i-1] and word2[0..j-1] */
    int dp[256];
    for (int j = 0; j <= n; j++) dp[j] = j;

    for (int i = 1; i <= m; i++) {
        /* 'prev' stores the diagonal value (dp[j-1] from previous row) */
        int prev = i - 1;
        dp[0] = i;

        for (int j = 1; j <= n; j++) {
            int temp = dp[j]; /* save before overwrite (the "up" value) */

            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prev;
            } else {
                /* min of: replace (prev), delete (temp), insert (dp[j-1]) */
                int x = prev < temp ? prev : temp;
                if (dp[j - 1] < x) x = dp[j - 1];
                dp[j] = x + 1;
            }

            prev = temp;
        }
    }

    return dp[n];
}

int main(void) {
    printf("%d\n", minDistance("horse",     "ros"));       /* 3 */
    printf("%d\n", minDistance("intention", "execution")); /* 5 */
    printf("%d\n", minDistance("",          "a"));         /* 1 */
    printf("%d\n", minDistance("a",         "a"));         /* 0 */
    printf("%d\n", minDistance("abc",       "def"));       /* 3 */
    return 0;
}
