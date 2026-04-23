#include <stdio.h>

int lengthOfLIS(int *nums, int n) {
    int tails[2500], size = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = size;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (tails[m] < nums[i]) l = m + 1;
            else r = m;
        }
        tails[l] = nums[i];
        if (l == size) ++size;
    }
    return size;
}

int main(void) {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    printf("%d\n", lengthOfLIS(nums, 8));
    return 0;
}
