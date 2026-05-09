#include <stdio.h>

static int search(int *nums, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        /* Left half is sorted */
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            /* Right half is sorted */
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int nums1[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums1, 7, 0));
    printf("%d\n", search(nums1, 7, 3));
    int nums2[] = {1};
    printf("%d\n", search(nums2, 1, 0));
    return 0;
}
