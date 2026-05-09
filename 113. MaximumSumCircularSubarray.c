#include <stdio.h>

static int maxSubarraySumCircular(int *nums, int n) {
    int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
    for (int i = 0; i < n; i++) {
        curMax = (curMax + nums[i] > nums[i]) ? curMax + nums[i] : nums[i];
        if (curMax > maxSum) maxSum = curMax;
        curMin = (curMin + nums[i] < nums[i]) ? curMin + nums[i] : nums[i];
        if (curMin < minSum) minSum = curMin;
        total += nums[i];
    }
    return maxSum > 0 ? (maxSum > total - minSum ? maxSum : total - minSum) : maxSum;
}

int main(void) {
    int nums1[] = {1, -2, 3, -2};
    printf("%d\n", maxSubarraySumCircular(nums1, 4));  /* 3 */
    int nums2[] = {5, -3, 5};
    printf("%d\n", maxSubarraySumCircular(nums2, 3));  /* 10 */
    int nums3[] = {-3, -2, -3};
    printf("%d\n", maxSubarraySumCircular(nums3, 3));  /* -2 */
    return 0;
}
