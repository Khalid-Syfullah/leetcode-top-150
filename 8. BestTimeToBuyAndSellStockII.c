#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main(void) {
    int a[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(a, 6)); /* 7 */

    int b[] = {1, 2, 3, 4, 5};
    printf("%d\n", maxProfit(b, 5)); /* 4 */

    int c[] = {7, 6, 4, 3, 1};
    printf("%d\n", maxProfit(c, 5)); /* 0 */

    return 0;
}
