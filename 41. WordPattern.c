#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool wordPattern(const char *pattern, const char *s) {
    /* Split s into words */
    char buf[1024];
    strncpy(buf, s, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *words[300];
    int wordCount = 0;
    char *tok = strtok(buf, " ");
    while (tok) { words[wordCount++] = tok; tok = strtok(NULL, " "); }

    int n = (int)strlen(pattern);
    if (n != wordCount) return false;

    /* Map char -> word and word -> char */
    char *cToW[256] = {0};
    /* For word -> char, use parallel arrays */
    char wKeys[300][64];
    char wVals[300];
    int wCount = 0;

    for (int i = 0; i < n; i++) {
        unsigned char c = (unsigned char)pattern[i];
        char *w = words[i];

        if (!cToW[c]) {
            /* Check word not already mapped to a different char */
            for (int j = 0; j < wCount; j++) {
                if (strcmp(wKeys[j], w) == 0) return false;
            }
            cToW[c] = w;
            strncpy(wKeys[wCount], w, 63);
            wKeys[wCount][63] = '\0';
            wVals[wCount] = (char)c;
            wCount++;
        } else {
            if (strcmp(cToW[c], w) != 0) return false;
            /* Also verify word->char is consistent */
            for (int j = 0; j < wCount; j++) {
                if (strcmp(wKeys[j], w) == 0) {
                    if (wVals[j] != (char)c) return false;
                    break;
                }
            }
        }
    }
    return true;
}

int main(void) {
    puts(wordPattern("abba", "dog cat cat dog")  ? "true" : "false"); // true
    puts(wordPattern("abba", "dog cat cat fish") ? "true" : "false"); // false
    puts(wordPattern("aaaa", "dog cat cat dog")  ? "true" : "false"); // false
    return 0;
}
