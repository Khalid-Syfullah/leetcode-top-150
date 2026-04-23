#include <stdio.h>
#include <string.h>

static void expand(const char *s, int l, int r, int *bestL, int *bestLen) {
    int n = (int)strlen(s);
    while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
    }
    int len = r - l - 1;
    if (len > *bestLen) {
        *bestLen = len;
        *bestL = l + 1;
    }
}

int main(void) {
    const char *s = "babad";
    int bestL = 0, bestLen = 0;
    for (int i = 0; s[i]; ++i) {
        expand(s, i, i, &bestL, &bestLen);
        expand(s, i, i + 1, &bestL, &bestLen);
    }
    printf("%.*s\n", bestLen, s + bestL);
    return 0;
}
