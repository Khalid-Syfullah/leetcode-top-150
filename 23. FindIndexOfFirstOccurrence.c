#include <stdio.h>
#include <string.h>

int strStr(const char *haystack, const char *needle) {
    int n = (int)strlen(haystack), m = (int)strlen(needle);
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
        if (strncmp(haystack + i, needle, (size_t)m) == 0) return i;
    }
    return -1;
}

int main(void) {
    printf("%d\n", strStr("sadbutsad", "sad"));  /* 0 */
    printf("%d\n", strStr("leetcode", "leeto")); /* -1 */
    printf("%d\n", strStr("hello", "ll"));       /* 2 */

    return 0;
}
