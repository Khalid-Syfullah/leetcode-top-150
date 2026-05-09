#include <stdio.h>
#include <stdlib.h>

/* Collect all combinations into a 2D result array */
static int **results;
static int resultCount;
static int kGlobal;

static void backtrack(int n, int k, int start, int depth, int *current) {
    if (depth == k) {
        results[resultCount] = malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) results[resultCount][i] = current[i];
        resultCount++;
        return;
    }
    for (int num = start; num <= n; num++) {
        current[depth] = num;
        backtrack(n, k, num + 1, depth + 1, current);
    }
}

static void combine(int n, int k) {
    /* max C(n,k) combos */
    int maxSize = 1;
    for (int i = 0; i < k; i++) maxSize = maxSize * (n - i) / (i + 1);
    maxSize += 10; /* safety */
    results = malloc(maxSize * sizeof(int *));
    resultCount = 0;
    kGlobal = k;
    int *current = malloc(k * sizeof(int));
    backtrack(n, k, 1, 0, current);
    free(current);

    printf("[");
    for (int i = 0; i < resultCount; i++) {
        printf("[");
        for (int j = 0; j < k; j++) {
            printf("%d%s", results[i][j], j < k - 1 ? ", " : "");
        }
        printf("]%s", i < resultCount - 1 ? ", " : "");
        free(results[i]);
    }
    printf("]\n");
    free(results);
}

int main(void) {
    combine(4, 2);
    combine(1, 1);
    return 0;
}
