#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char **results;
static int resultCount;

static void backtrack(int n, int open, int close, int idx, char *current) {
    if (idx == 2 * n) {
        current[idx] = '\0';
        results[resultCount] = malloc(idx + 1);
        strcpy(results[resultCount], current);
        resultCount++;
        return;
    }
    if (open < n) {
        current[idx] = '(';
        backtrack(n, open + 1, close, idx + 1, current);
    }
    if (close < open) {
        current[idx] = ')';
        backtrack(n, open, close + 1, idx + 1, current);
    }
}

/* Catalan number gives max results; 16 is enough for n<=8 */
static void generateParenthesis(int n) {
    results = malloc(1430 * sizeof(char *));
    resultCount = 0;
    char current[32];
    backtrack(n, 0, 0, 0, current);

    printf("[");
    for (int i = 0; i < resultCount; i++) {
        printf("%s%s", results[i], i < resultCount - 1 ? ", " : "");
        free(results[i]);
    }
    printf("]\n");
    free(results);
}

int main(void) {
    generateParenthesis(3);
    generateParenthesis(1);
    return 0;
}
