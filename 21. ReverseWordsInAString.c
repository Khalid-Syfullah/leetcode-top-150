#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseWords(const char *s) {
    int n = (int)strlen(s);
    char *out = malloc((size_t)n + 1);
    int k = 0, i = n - 1;
    while (i >= 0) {
        while (i >= 0 && isspace((unsigned char)s[i])) i--;
        if (i < 0) break;
        int end = i;
        while (i >= 0 && !isspace((unsigned char)s[i])) i--;
        if (k > 0) out[k++] = ' ';
        for (int j = i + 1; j <= end; j++) out[k++] = s[j];
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    char *r1 = reverseWords("the sky is blue");
    printf("%s\n", r1); /* blue is sky the */
    free(r1);

    char *r2 = reverseWords("  hello world  ");
    printf("%s\n", r2); /* world hello */
    free(r2);

    char *r3 = reverseWords("a good   example");
    printf("%s\n", r3); /* example good a */
    free(r3);

    return 0;
}
