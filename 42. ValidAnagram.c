#include <stdbool.h>
#include <stdio.h>

bool isAnagram(const char *s, const char *t) {
    int cnt[26] = {0};
    int i = 0;
    while (s[i]) ++cnt[s[i++] - 'a'];
    i = 0;
    while (t[i]) --cnt[t[i++] - 'a'];
    for (i = 0; i < 26; ++i) if (cnt[i] != 0) return false;
    return true;
}

int main(void) {
    puts(isAnagram("anagram", "nagaram") ? "true" : "false");
    return 0;
}
