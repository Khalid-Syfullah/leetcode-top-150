#include <stdio.h>
#include <stdlib.h>

int candy(int *ratings, int ratingsSize) {
    int n = ratingsSize;
    int *c = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++) c[i] = 1;

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
    }

    int total = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            int needed = c[i + 1] + 1;
            if (needed > c[i]) c[i] = needed;
        }
        total += c[i];
    }

    free(c);
    return total;
}

int main(void) {
    int a[] = {1, 0, 2};
    printf("%d\n", candy(a, 3)); /* 5 */

    int b[] = {1, 2, 2};
    printf("%d\n", candy(b, 3)); /* 4 */

    int d[] = {1, 3, 4, 5, 2};
    printf("%d\n", candy(d, 5)); /* 11 */

    return 0;
}
