#include <stdio.h>
#include <string.h>
#include <limits.h>

char result[100000];

char *minWindow(const char *s, const char *t) {
    int slen = (int)strlen(s);
    int tlen = (int)strlen(t);
    if (slen < tlen) { result[0] = '\0'; return result; }

    int need[128] = {0};
    for (int i = 0; i < tlen; i++) need[(unsigned char)t[i]]++;
    int missing = tlen, l = 0, start = 0, minLen = INT_MAX;

    for (int r = 0; r < slen; r++) {
        if (need[(unsigned char)s[r]]-- > 0) missing--;
        while (missing == 0) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            if (need[(unsigned char)s[l++]]++ == 0) missing++;
        }
    }
    if (minLen == INT_MAX) { result[0] = '\0'; return result; }
    memcpy(result, s + start, (size_t)minLen);
    result[minLen] = '\0';
    return result;
}

int main(void) {
    printf("%s\n", minWindow("ADOBECODEBANC", "ABC")); // BANC
    printf("%s\n", minWindow("a", "a"));               // a
    printf("%s\n", minWindow("a", "aa"));              // (empty)
    return 0;
}
