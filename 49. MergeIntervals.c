#include <stdio.h>
#include <stdlib.h>

static int cmp_interval(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return ia[0] - ib[0];
}

/* intervals: n x 2 array stored flat; result printed directly */
void merge(int (*intervals)[2], int n) {
    if (n == 0) return;
    qsort(intervals, (size_t)n, sizeof(int[2]), cmp_interval);

    int cur[2] = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= cur[1]) {
            if (intervals[i][1] > cur[1]) cur[1] = intervals[i][1];
        } else {
            printf("[%d, %d]\n", cur[0], cur[1]);
            cur[0] = intervals[i][0];
            cur[1] = intervals[i][1];
        }
    }
    printf("[%d, %d]\n", cur[0], cur[1]);
}

int main(void) {
    int a[][2] = {{1,3},{2,6},{8,10},{15,18}};
    merge(a, 4);
    printf("\n");

    int b[][2] = {{1,4},{4,5}};
    merge(b, 2);

    return 0;
}
