#include <stdio.h>
#include <string.h>

char *minWindow(const char *s, const char *t) {
    static char out[2048];
    int need[128] = {0}, missing = (int)strlen(t);
    for (int i = 0; t[i]; ++i) ++need[(unsigned char)t[i]];
    int bestStart = 0, bestLen = 1 << 30, left = 0;
    for (int right = 0; s[right]; ++right) {
        if (need[(unsigned char)s[right]] > 0) --missing;
        --need[(unsigned char)s[right]];
        while (missing == 0) {
            int len = right - left + 1;
            if (len < bestLen) {
                bestLen = len;
                bestStart = left;
            }
            ++need[(unsigned char)s[left]];
            if (need[(unsigned char)s[left]] > 0) ++missing;
            ++left;
        }
    }
    if (bestLen == (1 << 30)) {
        out[0] = '\0';
        return out;
    }
    memcpy(out, s + bestStart, (size_t)bestLen);
    out[bestLen] = '\0';
    return out;
}

int main(void) {
    puts(minWindow("ADOBECODEBANC", "ABC"));
    return 0;
}
