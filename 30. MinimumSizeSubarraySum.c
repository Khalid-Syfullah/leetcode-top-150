#include <limits.h>
#include <stdio.h>

int minSubArrayLen(int target, int *nums, int n) {
    int left = 0, sum = 0, best = INT_MAX;
    for (int right = 0; right < n; ++right) {
        sum += nums[right];
        while (sum >= target) {
            int len = right - left + 1;
            if (len < best) best = len;
            sum -= nums[left++];
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main(void) {
    int nums[] = {2, 3, 1, 2, 4, 3};
    printf("%d\n", minSubArrayLen(7, nums, 6));
    return 0;
}
