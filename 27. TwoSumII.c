#include <stdio.h>

void twoSum(int *numbers, int n, int target, int *a, int *b) {
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) { *a = l + 1; *b = r + 1; return; }
        if (sum < target) l++; else r--;
    }
    *a = *b = -1;
}

int main(void) {
    int res_a, res_b;

    int a[] = {2, 7, 11, 15};
    twoSum(a, 4, 9, &res_a, &res_b);
    printf("[%d, %d]\n", res_a, res_b); // [1, 2]

    int b[] = {2, 3, 4};
    twoSum(b, 3, 6, &res_a, &res_b);
    printf("[%d, %d]\n", res_a, res_b); // [1, 3]

    int c[] = {-1, 0};
    twoSum(c, 2, -1, &res_a, &res_b);
    printf("[%d, %d]\n", res_a, res_b); // [1, 2]

    return 0;
}
