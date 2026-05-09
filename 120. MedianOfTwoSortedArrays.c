#include <limits.h>
#include <stdio.h>

static double findMedianSortedArrays(int *nums1, int m, int *nums2, int n) {
    if (m > n) return findMedianSortedArrays(nums2, n, nums1, m);
    int left = 0;
    int right = m;
    while (left <= right) {
        int partition1 = left + (right - left) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                int leftMax = maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
                int rightMin = minRight1 < minRight2 ? minRight1 : minRight2;
                return (leftMax + rightMin) / 2.0;
            } else {
                return maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2;
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }
    return 0.0;
}

int main(void) {
    int a1[] = {1, 3};
    int b1[] = {2};
    printf("%.1f\n", findMedianSortedArrays(a1, 2, b1, 1));
    int a2[] = {1, 2};
    int b2[] = {3, 4};
    printf("%.1f\n", findMedianSortedArrays(a2, 2, b2, 2));
    int a3[] = {0, 0};
    int b3[] = {0, 0};
    printf("%.1f\n", findMedianSortedArrays(a3, 2, b3, 2));
    return 0;
}
