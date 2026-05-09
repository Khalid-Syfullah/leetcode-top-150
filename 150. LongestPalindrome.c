#include <stdio.h>
#include <string.h>

static int expand(const char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

/* Returns the start index and length of the longest palindromic substring */
static void longestPalindromeSubstr(const char *s, int *start, int *end) {
    int n = (int)strlen(s);
    *start = 0;
    *end = 0;

    for (int i = 0; i < n; i++) {
        int len1 = expand(s, i, i, n);       /* odd-length palindromes */
        int len2 = expand(s, i, i + 1, n);   /* even-length palindromes */
        int len = len1 > len2 ? len1 : len2;
        if (len > *end - *start) {
            *start = i - (len - 1) / 2;
            *end = i + len / 2;
        }
    }
}

int main(void) {
    const char *tests[] = {"babad", "cbbd", "a", "ac", "forgeeksskeegfor"};
    int numTests = 5;

    for (int t = 0; t < numTests; t++) {
        const char *s = tests[t];
        int start = 0, end = 0;
        longestPalindromeSubstr(s, &start, &end);
        int len = end - start + 1;
        printf("%.*s\n", len, s + start);
    }

    return 0;
}
