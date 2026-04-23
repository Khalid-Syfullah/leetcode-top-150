#include <stdbool.h>
#include <stdio.h>

bool isSubsequence(const char *s, const char *t) {
    int i = 0, j = 0;
    while (s[i] && t[j]) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return s[i] == '\0';
}

int main(void) {
    puts(isSubsequence("abc", "ahbgdc") ? "true" : "false");
    return 0;
}
