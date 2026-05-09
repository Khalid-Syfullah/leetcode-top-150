#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns a newly-allocated array and writes the new size into *retSize.
   Caller must free the returned pointer. */
int *plusOne(int *digits, int n, int *retSize) {
    /* Check if there is any digit < 9 from the right */
    int done = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            done = 1;
            break;
        }
        digits[i] = 0;
    }

    if (done) {
        int *result = (int *)malloc(n * sizeof(int));
        memcpy(result, digits, n * sizeof(int));
        *retSize = n;
        return result;
    }

    /* All digits were 9; need one extra digit */
    int *result = (int *)calloc(n + 1, sizeof(int));
    result[0] = 1;
    *retSize = n + 1;
    return result;
}

static void printArray(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    int retSize;
    int *result;

    int a[] = {1, 2, 3};
    result = plusOne(a, 3, &retSize);
    printArray(result, retSize); /* [1, 2, 4] */
    free(result);

    int b[] = {4, 3, 2, 1};
    result = plusOne(b, 4, &retSize);
    printArray(result, retSize); /* [4, 3, 2, 2] */
    free(result);

    int c[] = {9};
    result = plusOne(c, 1, &retSize);
    printArray(result, retSize); /* [1, 0] */
    free(result);

    int d[] = {9, 9, 9};
    result = plusOne(d, 3, &retSize);
    printArray(result, retSize); /* [1, 0, 0, 0] */
    free(result);

    return 0;
}
