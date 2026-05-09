#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int **results;
static int *resultSizes;
static int resultCount;

static void backtrack(int *candidates, int n, int remain, int start, int *current, int depth) {
    if (remain == 0) {
        results[resultCount] = malloc(depth * sizeof(int));
        memcpy(results[resultCount], current, depth * sizeof(int));
        resultSizes[resultCount] = depth;
        resultCount++;
        return;
    }
    for (int i = start; i < n; i++) {
        int value = candidates[i];
        if (value > remain) break;
        current[depth] = value;
        backtrack(candidates, n, remain - value, i, current, depth + 1);
    }
}

static int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static void combinationSum(int *candidates, int n, int target) {
    qsort(candidates, n, sizeof(int), cmp);
    results = malloc(200 * sizeof(int *));
    resultSizes = malloc(200 * sizeof(int));
    resultCount = 0;
    int current[64];
    backtrack(candidates, n, target, 0, current, 0);

    printf("[");
    for (int i = 0; i < resultCount; i++) {
        printf("[");
        for (int j = 0; j < resultSizes[i]; j++) {
            printf("%d%s", results[i][j], j < resultSizes[i] - 1 ? ", " : "");
        }
        printf("]%s", i < resultCount - 1 ? ", " : "");
        free(results[i]);
    }
    printf("]\n");
    free(results);
    free(resultSizes);
}

int main(void) {
    int cand1[] = {2, 3, 6, 7};
    combinationSum(cand1, 4, 7);
    int cand2[] = {2, 3, 5};
    combinationSum(cand2, 3, 8);
    int cand3[] = {2};
    combinationSum(cand3, 1, 1);
    return 0;
}
