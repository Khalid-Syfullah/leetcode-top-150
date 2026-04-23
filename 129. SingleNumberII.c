#include <stdio.h>

int singleNumber(int *nums, int n) {
    int ones = 0, twos = 0;
    for (int i = 0; i < n; ++i) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main(void) {
    int nums[] = {2, 2, 3, 2};
    printf("%d\n", singleNumber(nums, 4));
    return 0;
}
