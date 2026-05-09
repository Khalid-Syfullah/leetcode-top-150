#include <stdio.h>
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int n = numsSize;
    int *result = malloc((size_t)n * sizeof(int));
    *returnSize = n;

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

static void printArray(const int *a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(", ");
        printf("%d", a[i]);
    }
    printf("]\n");
}

int main(void) {
    int a[] = {1, 2, 3, 4};
    int rsize;
    int *ra = productExceptSelf(a, 4, &rsize);
    printArray(ra, rsize); /* [24, 12, 8, 6] */
    free(ra);

    int b[] = {-1, 1, 0, -3, 3};
    int *rb = productExceptSelf(b, 5, &rsize);
    printArray(rb, rsize); /* [0, 0, 9, 0, 0] */
    free(rb);

    return 0;
}
