#include <stdio.h>

/* Boyer-Moore Voting Algorithm: O(n) time, O(1) space */
int majorityElement(int *nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}

int main(void) {
    int a[] = {3, 2, 3};
    printf("%d\n", majorityElement(a, 3)); /* expected: 3 */

    int b[] = {2, 2, 1, 1, 1, 2, 2};
    printf("%d\n", majorityElement(b, 7)); /* expected: 2 */

    int c[] = {1};
    printf("%d\n", majorityElement(c, 1)); /* expected: 1 */

    return 0;
}
