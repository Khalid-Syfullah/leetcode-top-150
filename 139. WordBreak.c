#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool contains(const char *word, const char *dict[], int dictSize) {
    for (int i = 0; i < dictSize; ++i) {
        if (strcmp(word, dict[i]) == 0) return true;
    }
    return false;
}

bool wordBreak(const char *s, const char *dict[], int dictSize) {
    int n = (int)strlen(s);
    bool dp[256] = {false};
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (!dp[j]) continue;
            char part[256];
            memcpy(part, s + j, (size_t)(i - j));
            part[i - j] = '\0';
            if (contains(part, dict, dictSize)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main(void) {
    const char *dict[] = {"leet", "code"};
    puts(wordBreak("leetcode", dict, 2) ? "true" : "false");
    return 0;
}
