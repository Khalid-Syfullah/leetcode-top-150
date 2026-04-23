#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isInterleave(const char *s1, const char *s2, const char *s3) {
    int n = (int)strlen(s1), m = (int)strlen(s2);
    if (n + m != (int)strlen(s3)) return false;
    bool dp[128] = {false};
    dp[0] = true;
    for (int j = 1; j <= m; ++j) dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    for (int i = 1; i <= n; ++i) {
        dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= m; ++j) {
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[m];
}

int main(void) {
    puts(isInterleave("aabcc", "dbbca", "aadbbcbcac") ? "true" : "false");
    return 0;
}
