#include <limits.h>
#include <stdio.h>

int minSubArrayLen(int target, int *nums, int n) {
    int l = 0, sum = 0, best = INT_MAX;
    for (int r = 0; r < n; r++) {
        sum += nums[r];
        while (sum >= target) {
            int len = r - l + 1;
            if (len < best) best = len;
            sum -= nums[l++];
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main(void) {
    int a[] = {2, 3, 1, 2, 4, 3};
    printf("%d\n", minSubArrayLen(7, a, 6));    // 2

    int b[] = {1, 4, 4};
    printf("%d\n", minSubArrayLen(4, b, 3));    // 1

    int c[] = {1, 1, 1, 1, 1, 1, 1};
    printf("%d\n", minSubArrayLen(11, c, 7));   // 0

    return 0;
}
