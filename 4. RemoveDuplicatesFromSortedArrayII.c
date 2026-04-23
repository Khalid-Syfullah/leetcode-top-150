#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 2) return numsSize;
    int k = 2;
    for (int i = 2; i < numsSize; ++i) {
        if (nums[i] != nums[k - 2]) nums[k++] = nums[i];
    }
    return k;
}

int main(void) {
    int nums[] = {1, 1, 1, 2, 2, 3};
    printf("%d\n", removeDuplicates(nums, 6));
    return 0;
}
