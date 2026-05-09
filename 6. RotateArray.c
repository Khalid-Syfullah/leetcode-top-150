#include <stdio.h>

/* Reverse approach: O(n) time, O(1) space
   1. Reverse entire array
   2. Reverse first k elements
   3. Reverse remaining n-k elements */
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
    if (k == 0) return;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

static void printArray(const int *a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(", ");
        printf("%d", a[i]);
    }
    printf("]\n");
}

int main(void) {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums1, 7, 3);
    printf("Expected: [5, 6, 7, 1, 2, 3, 4]\n");
    printf("Actual:   ");
    printArray(nums1, 7);

    int nums2[] = {-1, -100, 3, 99};
    rotate(nums2, 4, 2);
    printf("Expected: [3, 99, -1, -100]\n");
    printf("Actual:   ");
    printArray(nums2, 4);

    int nums3[] = {1, 2};
    rotate(nums3, 2, 5);
    printf("Expected: [2, 1]\n");
    printf("Actual:   ");
    printArray(nums3, 2);

    return 0;
}
