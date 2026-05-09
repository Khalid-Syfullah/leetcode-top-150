#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Balloon;

static int cmp(const void *a, const void *b) {
    const Balloon *x = (const Balloon *)a;
    const Balloon *y = (const Balloon *)b;
    if (x->end < y->end) return -1;
    if (x->end > y->end) return 1;
    return 0;
}

int findMinArrowShots(Balloon *points, int n) {
    if (n == 0) return 0;
    qsort(points, (size_t)n, sizeof(Balloon), cmp);
    int arrows = 1;
    int arrowPos = points[0].end;
    for (int i = 1; i < n; i++) {
        if (points[i].start > arrowPos) {
            arrows++;
            arrowPos = points[i].end;
        }
    }
    return arrows;
}

int main(void) {
    Balloon points1[] = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Balloon points2[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Balloon points3[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    printf("%d\n", findMinArrowShots(points1, 4));
    printf("%d\n", findMinArrowShots(points2, 4));
    printf("%d\n", findMinArrowShots(points3, 4));

    return 0;
}
