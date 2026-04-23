#include <stdio.h>

typedef struct {
    int start;
    int end;
} Interval;

void insert(Interval *intervals, int n, Interval newInterval) {
    int i = 0;
    while (i < n && intervals[i].end < newInterval.start) {
        printf("[%d, %d]\n", intervals[i].start, intervals[i].end);
        ++i;
    }
    while (i < n && intervals[i].start <= newInterval.end) {
        if (intervals[i].start < newInterval.start) newInterval.start = intervals[i].start;
        if (intervals[i].end > newInterval.end) newInterval.end = intervals[i].end;
        ++i;
    }
    printf("[%d, %d]\n", newInterval.start, newInterval.end);
    while (i < n) {
        printf("[%d, %d]\n", intervals[i].start, intervals[i].end);
        ++i;
    }
}

int main(void) {
    Interval intervals[] = {{1, 3}, {6, 9}};
    insert(intervals, 2, (Interval){2, 5});
    return 0;
}
