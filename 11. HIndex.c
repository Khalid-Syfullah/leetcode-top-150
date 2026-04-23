#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b) {
    return *(const int *)b - *(const int *)a;
}

int hIndex(int *citations, int n) {
    qsort(citations, (size_t)n, sizeof(int), cmp);
    int h = 0;
    while (h < n && citations[h] > h) ++h;
    return h;
}

int main(void) {
    int citations[] = {3, 0, 6, 1, 5};
    printf("%d\n", hIndex(citations, 5));
    return 0;
}
