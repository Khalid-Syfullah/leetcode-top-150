#include <limits.h>
#include <stdio.h>

int maxProfit(int *prices, int n) {
    int buy1  = INT_MIN;
    int sell1 = 0;
    int buy2  = INT_MIN;
    int sell2 = 0;

    for (int i = 0; i < n; i++) {
        int p = prices[i];
        if (-p > buy1)            buy1  = -p;           /* min cost for 1st buy */
        if (buy1 + p > sell1)     sell1 = buy1 + p;     /* max profit after 1st sell */
        if (sell1 - p > buy2)     buy2  = sell1 - p;    /* min effective cost for 2nd buy */
        if (buy2 + p > sell2)     sell2 = buy2 + p;     /* max profit after 2nd sell */
    }

    return sell2;
}

int main(void) {
    int a[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("%d\n", maxProfit(a, 8)); /* 6 */

    int b[] = {1, 2, 3, 4, 5};
    printf("%d\n", maxProfit(b, 5)); /* 4 */

    int c[] = {7, 6, 4, 3, 1};
    printf("%d\n", maxProfit(c, 5)); /* 0 */

    int d[] = {1, 2};
    printf("%d\n", maxProfit(d, 2)); /* 1 */

    return 0;
}
