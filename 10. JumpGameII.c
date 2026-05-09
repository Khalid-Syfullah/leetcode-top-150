#include <stdio.h>

int jump(int *nums, int numsSize) {
    int jumps = 0, end = 0, far = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > far) far = i + nums[i];
        if (i == end) {
            jumps++;
            end = far;
        }
    }
    return jumps;
}

int main(void) {
    int a[] = {2, 3, 1, 1, 4};
    printf("%d\n", jump(a, 5)); /* 2 */

    int b[] = {2, 3, 0, 1, 4};
    printf("%d\n", jump(b, 5)); /* 2 */

    int c[] = {1};
    printf("%d\n", jump(c, 1)); /* 0 */

    return 0;
}
