#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
    }
    return ans;
}

int main(void) {
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, 6));
    return 0;
}
