#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isSubsequence(const char *s, const char *t) {
    int i = 0;
    int slen = (int)strlen(s);
    int tlen = (int)strlen(t);
    for (int j = 0; j < tlen && i < slen; j++) {
        if (s[i] == t[j]) i++;
    }
    return i == slen;
}

int main(void) {
    puts(isSubsequence("abc", "ahbgdc") ? "true" : "false"); // true
    puts(isSubsequence("axc", "ahbgdc") ? "true" : "false"); // false
    puts(isSubsequence("", "abc")       ? "true" : "false"); // true
    return 0;
}
