#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}

int main(void) {
    int nums[] = {3, 2, 2, 3};
    int k = removeElement(nums, 4, 3);
    printf("%d\n", k);
    for (int i = 0; i < k; ++i) printf("%d ", nums[i]);
    puts("");
    return 0;
}
