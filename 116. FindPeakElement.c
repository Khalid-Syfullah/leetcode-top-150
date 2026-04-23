#include <stdio.h>

int findPeakElement(int *nums, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main(void) {
    int nums[] = {1, 2, 1, 3, 5, 6, 4};
    printf("%d\n", findPeakElement(nums, 7));
    return 0;
}
