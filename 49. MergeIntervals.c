#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

static int cmp(const void *a, const void *b) {
    return ((const Interval *)a)->start - ((const Interval *)b)->start;
}

void merge(Interval *intervals, int n) {
    qsort(intervals, (size_t)n, sizeof(Interval), cmp);
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (intervals[i].start <= intervals[idx].end) {
            if (intervals[i].end > intervals[idx].end) intervals[idx].end = intervals[i].end;
        } else {
            intervals[++idx] = intervals[i];
        }
    }
    for (int i = 0; i <= idx; ++i) printf("[%d, %d]\n", intervals[i].start, intervals[i].end);
}

int main(void) {
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge(intervals, 4);
    return 0;
}
