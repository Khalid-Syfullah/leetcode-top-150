#include <limits.h>
#include <stdio.h>

int maxProfit(int *prices, int pricesSize) {
    int best = 0, low = INT_MAX;
    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < low) low = prices[i];
        if (prices[i] - low > best) best = prices[i] - low;
    }
    return best;
}

int main(void) {
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, 6));
    return 0;
}
