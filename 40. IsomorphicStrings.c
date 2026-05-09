#include <stdbool.h>
#include <stdio.h>

bool isIsomorphic(const char *s, const char *t) {
    int ms[256] = {0}, mt[256] = {0};
    for (int i = 0; s[i] && t[i]; i++) {
        unsigned char a = (unsigned char)s[i], b = (unsigned char)t[i];
        if (ms[a] != mt[b]) return false;
        ms[a] = mt[b] = i + 1;
    }
    return true;
}

int main(void) {
    puts(isIsomorphic("egg",   "add")   ? "true" : "false"); // true
    puts(isIsomorphic("foo",   "bar")   ? "true" : "false"); // false
    puts(isIsomorphic("paper", "title") ? "true" : "false"); // true
    return 0;
}
