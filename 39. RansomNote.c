#include <stdbool.h>
#include <stdio.h>

bool canConstruct(const char *ransomNote, const char *magazine) {
    int count[26] = {0};
    for (int i = 0; magazine[i]; i++) count[magazine[i] - 'a']++;
    for (int i = 0; ransomNote[i]; i++) {
        if (--count[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}

int main(void) {
    puts(canConstruct("a",  "b")   ? "true" : "false"); // false
    puts(canConstruct("aa", "ab")  ? "true" : "false"); // false
    puts(canConstruct("aa", "aab") ? "true" : "false"); // true
    return 0;
}
