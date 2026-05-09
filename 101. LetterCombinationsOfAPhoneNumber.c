#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

/* Results stored in a dynamic array of strings */
static char **results;
static int resultCount;
static char current[16];

static void dfs(const char *digits, int idx, int len) {
    if (idx == len) {
        results[resultCount] = malloc(len + 1);
        strcpy(results[resultCount], current);
        resultCount++;
        return;
    }
    const char *letters = map[digits[idx] - '0'];
    for (int i = 0; letters[i]; i++) {
        current[idx] = letters[i];
        current[idx + 1] = '\0';
        dfs(digits, idx + 1, len);
    }
}

static void letterCombinations(const char *digits) {
    int len = (int)strlen(digits);
    if (len == 0) {
        printf("[]\n");
        return;
    }
    /* max 4^len combinations */
    int maxSize = 1;
    for (int i = 0; i < len; i++) maxSize *= 4;
    results = malloc(maxSize * sizeof(char *));
    resultCount = 0;
    current[0] = '\0';
    dfs(digits, 0, len);
    printf("[");
    for (int i = 0; i < resultCount; i++) {
        printf("%s%s", results[i], i < resultCount - 1 ? ", " : "");
        free(results[i]);
    }
    printf("]\n");
    free(results);
}

int main(void) {
    letterCombinations("23"); /* [ad, ae, af, bd, be, bf, cd, ce, cf] */
    letterCombinations("");   /* [] */
    letterCombinations("2");  /* [a, b, c] */
    return 0;
}
