#include <stdio.h>

int findMin(int *nums, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

int main(void) {
    int nums[] = {3, 4, 5, 1, 2};
    printf("%d\n", findMin(nums, 5));
    return 0;
}
