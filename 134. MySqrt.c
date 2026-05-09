#include <stdio.h>

int mySqrt(int x) {
    if (x < 2) {
        return x;
    }

    int left = 1, right = x / 2, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        long long square = (long long)mid * mid;

        if (square < x) {
            ans = mid;
            left = mid + 1;
        } else if (square > x) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return ans;
}

int main(void) {
    printf("%d\n", mySqrt(4));          /* 2 */
    printf("%d\n", mySqrt(8));          /* 2 */
    printf("%d\n", mySqrt(0));          /* 0 */
    printf("%d\n", mySqrt(1));          /* 1 */
    printf("%d\n", mySqrt(2147395599)); /* 46339 */
    return 0;
}
