#include <stdio.h>

int search(int *nums, int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m]) r = m - 1;
            else l = m + 1;
        } else {
            if (nums[m] < target && target <= nums[r]) l = m + 1;
            else r = m - 1;
        }
    }
    return -1;
}

int main(void) {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums, 7, 0));
    return 0;
}
