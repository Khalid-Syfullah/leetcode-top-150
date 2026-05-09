#include <stdio.h>

static int findMin(int *nums, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

int main(void) {
    int nums1[] = {3, 4, 5, 1, 2};
    printf("%d\n", findMin(nums1, 5));
    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", findMin(nums2, 7));
    int nums3[] = {11, 13, 15, 17};
    printf("%d\n", findMin(nums3, 4));
    return 0;
}
