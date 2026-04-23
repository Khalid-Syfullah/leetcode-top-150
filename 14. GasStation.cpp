#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
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

int main() {
    vector<int> g1 = {1, 2, 3, 4, 5}, c1 = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(g1, c1) << "\n";

    vector<int> g2 = {2, 3, 4}, c2 = {3, 4, 3};
    cout << canCompleteCircuit(g2, c2) << "\n";

    return 0;
}
