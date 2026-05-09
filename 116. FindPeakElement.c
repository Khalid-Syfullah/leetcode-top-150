#include <stdio.h>

static int findPeak(int *nums, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(void) {
    int nums1[] = {1, 2, 3, 1};
    printf("%d\n", findPeak(nums1, 4));
    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    printf("%d\n", findPeak(nums2, 7));
    int nums3[] = {1};
    printf("%d\n", findPeak(nums3, 1));
    return 0;
}
