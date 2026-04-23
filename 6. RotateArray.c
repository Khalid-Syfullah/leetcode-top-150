#include <stdio.h>

static void reverse(int *nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}

void rotate(int *nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 7, 3);
    for (int i = 0; i < 7; ++i) printf("%d ", nums[i]);
    puts("");
    return 0;
}
