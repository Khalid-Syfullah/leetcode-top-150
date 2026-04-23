#include <stdio.h>

int maxSubarraySumCircular(int *nums, int n) {
    int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
    for (int i = 0; i < n; ++i) {
        curMax = curMax > 0 ? curMax + nums[i] : nums[i];
        if (curMax > maxSum) maxSum = curMax;
        curMin = curMin < 0 ? curMin + nums[i] : nums[i];
        if (curMin < minSum) minSum = curMin;
        total += nums[i];
    }
    if (maxSum < 0) return maxSum;
    return maxSum > total - minSum ? maxSum : total - minSum;
}

int main(void) {
    int nums[] = {1, -2, 3, -2};
    printf("%d\n", maxSubarraySumCircular(nums, 4));
    return 0;
}
