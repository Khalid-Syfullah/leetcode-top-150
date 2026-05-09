#include <stdio.h>
#include <string.h>

/* Returns the longest common prefix in a static buffer */
char *longestCommonPrefix(char **strs, int n) {
    static char out[256];
    if (n == 0) { out[0] = '\0'; return out; }
    /* Start with first string as prefix, shrink until all match */
    strncpy(out, strs[0], 255);
    out[255] = '\0';
    for (int i = 1; i < n; i++) {
        int len = (int)strlen(out);
        while (len > 0 && strncmp(strs[i], out, (size_t)len) != 0) {
            len--;
            out[len] = '\0';
        }
        if (len == 0) return out;
    }
    return out;
}

int main(void) {
    char *a[] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(a, 3)); /* fl */

    char *b[] = {"dog", "racecar", "car"};
    printf("%s\n", longestCommonPrefix(b, 3)); /* (empty) */

    char *c[] = {"a"};
    printf("%s\n", longestCommonPrefix(c, 1)); /* a */

    return 0;
}
