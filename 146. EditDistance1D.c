#include <stdio.h>
#include <string.h>

int minDistance(const char *a, const char *b) {
    int n = (int)strlen(a), m = (int)strlen(b);
    int dp[256];
    for (int j = 0; j <= m; ++j) dp[j] = j;
    for (int i = 1; i <= n; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= m; ++j) {
            int saved = dp[j];
            if (a[i - 1] == b[j - 1]) dp[j] = prev;
            else {
                int x = dp[j] < dp[j - 1] ? dp[j] : dp[j - 1];
                if (prev < x) x = prev;
                dp[j] = x + 1;
            }
            prev = saved;
        }
    }
    return dp[m];
}

int main(void) {
    printf("%d\n", minDistance("horse", "ros"));
    return 0;
}
