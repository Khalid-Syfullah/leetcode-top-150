#include <limits.h>
#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    int min = INT_MAX, best = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min) min = prices[i];
        else if (prices[i] - min > best) best = prices[i] - min;
    }
    return best;
}

int main(void) {
    int a[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(a, 6)); /* 5 */

    int b[] = {7, 6, 4, 3, 1};
    printf("%d\n", maxProfit(b, 5)); /* 0 */

    int c[] = {2, 4, 1};
    printf("%d\n", maxProfit(c, 3)); /* 2 */

    return 0;
}
