#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

static void print_array(const int *a, int n) {
    putchar('[');
    for (int i = 0; i < n; ++i) {
        if (i) printf(", ");
        printf("%d", a[i]);
    }
    puts("]");
}

int main(void) {
    int a[] = {1, 2, 3, 0, 0, 0};
    int b[] = {2, 5, 6};
    merge(a, 3, b, 3);
    print_array(a, 6);
    return 0;
}
