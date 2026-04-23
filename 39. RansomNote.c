#include <stdbool.h>
#include <stdio.h>

bool canConstruct(const char *ransomNote, const char *magazine) {
    int cnt[26] = {0};
    for (int i = 0; magazine[i]; ++i) ++cnt[magazine[i] - 'a'];
    for (int i = 0; ransomNote[i]; ++i) {
        if (--cnt[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}

int main(void) {
    puts(canConstruct("aa", "aab") ? "true" : "false");
    return 0;
}
