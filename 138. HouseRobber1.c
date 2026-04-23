#include <stdio.h>

int rob(int *nums, int n) {
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i < n; ++i) {
        int take = prev2 + nums[i];
        int curr = take > prev1 ? take : prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(void) {
    int nums[] = {2, 7, 9, 3, 1};
    printf("%d\n", rob(nums, 5));
    return 0;
}
