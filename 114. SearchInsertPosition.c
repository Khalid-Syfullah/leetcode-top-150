#include <stdio.h>

int searchInsert(int *nums, int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main(void) {
    int nums[] = {1, 3, 5, 6};
    printf("%d\n", searchInsert(nums, 4, 5));
    return 0;
}
