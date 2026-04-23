#include <stdio.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
    (void)costSize;
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gasSize; ++i) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    return total < 0 ? -1 : start;
}

int main(void) {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    printf("%d\n", canCompleteCircuit(gas, 5, cost, 5));
    return 0;
}
