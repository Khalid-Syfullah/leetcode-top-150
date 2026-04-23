#include <stdio.h>

int maxSubArray(int *nums, int n) {
    int best = nums[0], curr = nums[0];
    for (int i = 1; i < n; ++i) {
        curr = (curr > 0) ? curr + nums[i] : nums[i];
        if (curr > best) best = curr;
    }
    return best;
}

int main(void) {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(nums, 9));
    return 0;
}
