#include <stdio.h>

static int maxSubArray(int *nums, int n) {
    int currentSum = nums[0];
    int bestSum = nums[0];
    for (int i = 1; i < n; i++) {
        currentSum = (currentSum + nums[i] > nums[i]) ? currentSum + nums[i] : nums[i];
        if (currentSum > bestSum) bestSum = currentSum;
    }
    return bestSum;
}

int main(void) {
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSubArray(nums1, 9));
    int nums2[] = {1};
    printf("%d\n", maxSubArray(nums2, 1));
    int nums3[] = {5, 4, -1, 7, 8};
    printf("%d\n", maxSubArray(nums3, 5));
    return 0;
}
