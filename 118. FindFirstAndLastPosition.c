#include <stdio.h>

static int lowerBound(int *nums, int n, int target) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main(void) {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int first = lowerBound(nums, 6, 8);
    int last = lowerBound(nums, 6, 9) - 1;
    if (first == 6 || nums[first] != 8) first = last = -1;
    printf("[%d, %d]\n", first, last);
    return 0;
}
