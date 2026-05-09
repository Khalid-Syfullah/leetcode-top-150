#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool contains(const char *word, const char *dict[], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dict[i]) == 0) return true;
    }
    return false;
}

bool isWordBreak(const char *s, const char *dict[], int dictSize) {
    if (s == NULL) return false;

    int n = (int)strlen(s);
    bool dp[256];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
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
    const char *dict1[] = {"leet", "code"};
    puts(isWordBreak("leetcode", dict1, 2) ? "true" : "false"); /* true */

    const char *dict2[] = {"apple", "pen"};
    puts(isWordBreak("applepenapple", dict2, 2) ? "true" : "false"); /* true */

    const char *dict3[] = {"cats", "dog", "sand", "and", "cat"};
    puts(isWordBreak("catsandog", dict3, 5) ? "true" : "false"); /* false */

    const char *dict4[] = {"a"};
    puts(isWordBreak("", dict4, 1) ? "true" : "false"); /* true */

    puts(isWordBreak("a", NULL, 0) ? "true" : "false"); /* false */

    return 0;
}
