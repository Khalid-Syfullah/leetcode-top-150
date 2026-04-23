#include <limits.h>
#include <stdio.h>

int maxProfit(int *prices, int n) {
    int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
    for (int i = 0; i < n; ++i) {
        if (-prices[i] > buy1) buy1 = -prices[i];
        if (buy1 + prices[i] > sell1) sell1 = buy1 + prices[i];
        if (sell1 - prices[i] > buy2) buy2 = sell1 - prices[i];
        if (buy2 + prices[i] > sell2) sell2 = buy2 + prices[i];
    }
    return sell2;
}

int main(void) {
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("%d\n", maxProfit(prices, 8));
    return 0;
}
