#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sort-based approach: sort, then scan for consecutive runs */
static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int longestConsecutive(int *nums, int n) {
    if (n == 0) return 0;

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    memcpy(arr, nums, (size_t)n * sizeof(int));
    qsort(arr, (size_t)n, sizeof(int), cmp_int);

    int longest = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) continue;       /* duplicate, skip */
        if (arr[i] == arr[i - 1] + 1) {
            cur++;
            if (cur > longest) longest = cur;
        } else {
            cur = 1;
        }
    }
    free(arr);
    return longest;
}

int main(void) {
    int a[] = {100, 4, 200, 1, 3, 2};
    printf("%d\n", longestConsecutive(a, 6));  // 4

    int b[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    printf("%d\n", longestConsecutive(b, 10)); // 9

    printf("%d\n", longestConsecutive(NULL, 0)); // 0

    return 0;
}
