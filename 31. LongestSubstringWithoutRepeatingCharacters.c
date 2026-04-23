#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char *s) {
    int last[256];
    for (int i = 0; i < 256; ++i) last[i] = -1;
    int best = 0, left = 0;
    for (int right = 0; s[right]; ++right) {
        unsigned char c = (unsigned char)s[right];
        if (last[c] >= left) left = last[c] + 1;
        last[c] = right;
        if (right - left + 1 > best) best = right - left + 1;
    }
    return best;
}

int main(void) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    return 0;
}
