#include <limits.h>
#include <stdio.h>

double findMedianSortedArrays(int *a, int m, int *b, int n) {
    if (m > n) return findMedianSortedArrays(b, n, a, m);
    int totalLeft = (m + n + 1) / 2;
    int left = 0, right = m;
    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = totalLeft - i;
        int aLeft = i == 0 ? INT_MIN : a[i - 1];
        int aRight = i == m ? INT_MAX : a[i];
        int bLeft = j == 0 ? INT_MIN : b[j - 1];
        int bRight = j == n ? INT_MAX : b[j];
        if (aLeft <= bRight && bLeft <= aRight) {
            if ((m + n) % 2) return aLeft > bLeft ? aLeft : bLeft;
            int leftMax = aLeft > bLeft ? aLeft : bLeft;
            int rightMin = aRight < bRight ? aRight : bRight;
            return (leftMax + rightMin) / 2.0;
        }
        if (aLeft > bRight) right = i - 1;
        else left = i + 1;
    }
    return 0.0;
}

int main(void) {
    int a[] = {1, 3};
    int b[] = {2};
    printf("%.1f\n", findMedianSortedArrays(a, 2, b, 1));
    return 0;
}
