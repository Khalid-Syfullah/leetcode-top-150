#include <stdio.h>

int rob(int *nums, int n) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < n; i++) {
        int curr = prev2 + nums[i];
        if (curr < prev1) curr = prev1;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(void) {
    int a[] = {1, 2, 3, 1};
    int b[] = {2, 7, 9, 3, 1};
    int c[] = {2};
    int d[] = {6, 6, 4, 8, 4, 3, 3, 10};

    printf("%d\n", rob(a, 4));    /* 4 */
    printf("%d\n", rob(b, 5));    /* 12 */
    printf("%d\n", rob(c, 1));    /* 2 */
    printf("%d\n", rob(NULL, 0)); /* 0 */
    printf("%d\n", rob(d, 8));    /* 27 */
    return 0;
}
