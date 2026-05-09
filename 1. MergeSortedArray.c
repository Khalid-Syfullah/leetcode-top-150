#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
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
    int a[] = {1, 2, 3, 0, 0, 0};
    int b2[] = {2, 5, 6};
    merge(a, 3, b2, 3);
    printArray(a, 6); // [1, 2, 2, 3, 5, 6]

    int b[] = {1};
    int empty[] = {0}; /* placeholder, n=0 so unused */
    merge(b, 1, empty, 0);
    printArray(b, 1); // [1]

    int c[] = {0};
    int one[] = {1};
    merge(c, 0, one, 1);
    printArray(c, 1); // [1]

    return 0;
}
