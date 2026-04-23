#include <stdio.h>

int jump(int *nums, int numsSize) {
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        if (i + nums[i] > farthest) farthest = i + nums[i];
        if (i == end) {
            ++jumps;
            end = farthest;
        }
    }
    return jumps;
}

int main(void) {
    int nums[] = {2, 3, 1, 1, 4};
    printf("%d\n", jump(nums, 5));
    return 0;
}
