#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int **results;
static int resultCount;
static int nGlobal;

static void backtrack(int *nums, int n, bool *used, int *current, int depth) {
    if (depth == n) {
        results[resultCount] = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) results[resultCount][i] = current[i];
        resultCount++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        current[depth] = nums[i];
        backtrack(nums, n, used, current, depth + 1);
        used[i] = false;
    }
}

static void permute(int *nums, int n) {
    /* max n! permutations */
    int maxSize = 1;
    for (int i = 1; i <= n; i++) maxSize *= i;
    results = malloc(maxSize * sizeof(int *));
    resultCount = 0;
    nGlobal = n;
    bool *used = calloc(n, sizeof(bool));
    int *current = malloc(n * sizeof(int));
    backtrack(nums, n, used, current, 0);
    free(used);
    free(current);

    printf("[");
    for (int i = 0; i < resultCount; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d%s", results[i][j], j < n - 1 ? ", " : "");
        }
        printf("]%s", i < resultCount - 1 ? ", " : "");
        free(results[i]);
    }
    printf("]\n");
    free(results);
}

int main(void) {
    int nums1[] = {1, 2, 3};
    permute(nums1, 3);
    int nums2[] = {0, 1};
    permute(nums2, 2);
    int nums3[] = {1};
    permute(nums3, 1);
    return 0;
}
