#include <stdio.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize) {
    (void)costSize;
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int main(void) {
    int gas1[] = {1, 2, 3, 4, 5};
    int cost1[] = {3, 4, 5, 1, 2};
    printf("%d\n", canCompleteCircuit(gas1, 5, cost1, 5)); /* 3 */

    int gas2[] = {2, 3, 4};
    int cost2[] = {3, 4, 3};
    printf("%d\n", canCompleteCircuit(gas2, 3, cost2, 3)); /* -1 */

    return 0;
}
