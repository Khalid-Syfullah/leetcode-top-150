#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool wordPattern(const char *pattern, char *s) {
    char *words[300];
    int wordCount = 0;
    for (char *tok = strtok(s, " "); tok; tok = strtok(NULL, " ")) words[wordCount++] = tok;
    int n = (int)strlen(pattern);
    if (n != wordCount) return false;
    char *mapP[256] = {0};
    char used[300][64];
    int usedCount = 0;
    for (int i = 0; i < n; ++i) {
        unsigned char p = (unsigned char)pattern[i];
        if (!mapP[p]) {
            for (int j = 0; j < usedCount; ++j) {
                if (strcmp(used[j], words[i]) == 0) return false;
            }
            mapP[p] = words[i];
            strcpy(used[usedCount++], words[i]);
        } else if (strcmp(mapP[p], words[i]) != 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char s[] = "dog cat cat dog";
    puts(wordPattern("abba", s) ? "true" : "false");
    return 0;
}
