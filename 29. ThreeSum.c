#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

/* Print all triplets summing to zero; format: [[-1,-1,2],[-1,0,1]] */
void threeSum(int *nums, int n) {
    qsort(nums, (size_t)n, sizeof(int), cmp_int);
    int first = 1;
    printf("[");
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                if (!first) printf(", ");
                printf("[%d, %d, %d]", nums[i], nums[l], nums[r]);
                first = 0;
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++; r--;
            } else if (sum < 0) l++;
            else r--;
        }
    }
    printf("]\n");
}

int main(void) {
    int a[] = {-1, 0, 1, 2, -1, -4};
    threeSum(a, 6); // [[-1,-1,2],[-1,0,1]]

    int b[] = {0, 1, 1};
    threeSum(b, 3); // []

    int c[] = {0, 0, 0};
    threeSum(c, 3); // [[0,0,0]]

    return 0;
}
