#include <stdbool.h>
#include <stdio.h>

bool canJump(int *nums, int numsSize) {
    int reach = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i > reach) return false;
        if (i + nums[i] > reach) reach = i + nums[i];
    }
    return true;
}

int main(void) {
    int nums[] = {2, 3, 1, 1, 4};
    printf("%s\n", canJump(nums, 5) ? "true" : "false");
    return 0;
}
