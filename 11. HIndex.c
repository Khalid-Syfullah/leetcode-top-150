#include <stdio.h>
#include <stdlib.h>

static int cmpAsc(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

int hIndex(int *citations, int n) {
    qsort(citations, (size_t)n, sizeof(int), cmpAsc);
    for (int i = 0; i < n; i++) {
        int h = n - i;
        if (citations[i] >= h) return h;
    }
    return 0;
}

int main(void) {
    int a[] = {3, 0, 6, 1, 5};
    printf("%d\n", hIndex(a, 5)); /* 3 */

    int b[] = {1, 3, 1};
    printf("%d\n", hIndex(b, 3)); /* 1 */

    int c[] = {0};
    printf("%d\n", hIndex(c, 1)); /* 0 */

    return 0;
}
