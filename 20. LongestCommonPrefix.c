#include <stdio.h>

char *longestCommonPrefix(char **strs, int n) {
    static char out[256];
    int k = 0;
    while (strs[0][k]) {
        char ch = strs[0][k];
        for (int i = 1; i < n; ++i) {
            if (strs[i][k] != ch) {
                out[k] = '\0';
                return out;
            }
        }
        out[k++] = ch;
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    char *strs[] = {"flower", "flow", "flight"};
    puts(longestCommonPrefix(strs, 3));
    return 0;
}
