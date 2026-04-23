#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(const char *s) {
    int n = (int)strlen(s);
    char *out = malloc((size_t)n + 1);
    int k = 0, i = n - 1;
    while (i >= 0) {
        while (i >= 0 && isspace((unsigned char)s[i])) --i;
        if (i < 0) break;
        int end = i;
        while (i >= 0 && !isspace((unsigned char)s[i])) --i;
        if (k > 0) out[k++] = ' ';
        for (int j = i + 1; j <= end; ++j) out[k++] = s[j];
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    char *ans = reverseWords("  hello   world  ");
    puts(ans);
    free(ans);
    return 0;
}
