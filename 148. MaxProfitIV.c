#include <limits.h>
#include <stdio.h>

int maxProfit(int k, int *prices, int n) {
    int buy[101], sell[101];
    for (int i = 0; i <= k; ++i) {
        buy[i] = INT_MIN / 2;
        sell[i] = 0;
    }
    for (int p = 0; p < n; ++p) {
        for (int t = 1; t <= k; ++t) {
            if (sell[t - 1] - prices[p] > buy[t]) buy[t] = sell[t - 1] - prices[p];
            if (buy[t] + prices[p] > sell[t]) sell[t] = buy[t] + prices[p];
        }
    }
    return sell[k];
}

int main(void) {
    int prices[] = {2, 4, 1};
    printf("%d\n", maxProfit(2, prices, 3));
    return 0;
}
