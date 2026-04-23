#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Balloon;

static int cmp(const void *a, const void *b) {
    const Balloon *x = a, *y = b;
    if (x->end < y->end) return -1;
    if (x->end > y->end) return 1;
    return 0;
}

int findMinArrowShots(Balloon *points, int n) {
    qsort(points, (size_t)n, sizeof(Balloon), cmp);
    int arrows = 1;
    int end = points[0].end;
    for (int i = 1; i < n; ++i) {
        if (points[i].start > end) {
            ++arrows;
            end = points[i].end;
        }
    }
    return arrows;
}

int main(void) {
    Balloon points[] = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    printf("%d\n", findMinArrowShots(points, 4));
    return 0;
}
