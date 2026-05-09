#include <stdbool.h>
#include <stdio.h>

bool canJump(int *nums, int numsSize) {
    int reach = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > reach) return false;
        if (i + nums[i] > reach) reach = i + nums[i];
    }
    return true;
}

int main(void) {
    int a[] = {2, 3, 1, 1, 4};
    printf("%s\n", canJump(a, 5) ? "true" : "false"); /* true */

    int b[] = {3, 2, 1, 0, 4};
    printf("%s\n", canJump(b, 5) ? "true" : "false"); /* false */

    int c[] = {0};
    printf("%s\n", canJump(c, 1) ? "true" : "false"); /* true */

    return 0;
}
