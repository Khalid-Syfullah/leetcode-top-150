#include <stdio.h>

int lengthOfLongestSubstring(const char *s) {
    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;
    int l = 0, best = 0;
    for (int r = 0; s[r]; r++) {
        unsigned char c = (unsigned char)s[r];
        if (last[c] >= l) l = last[c] + 1;
        last[c] = r;
        if (r - l + 1 > best) best = r - l + 1;
    }
    return best;
}

int main(void) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); // 3
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));    // 1
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));   // 3
    printf("%d\n", lengthOfLongestSubstring(""));         // 0
    return 0;
}
