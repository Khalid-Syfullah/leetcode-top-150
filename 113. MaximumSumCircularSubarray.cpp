#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
    for (int n : nums) {
        curMax = max(curMax + n, n);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + n, n);
        minSum = min(minSum, curMin);
        total += n;
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}

int main() {
    vector<int> v1 = {1, -2, 3, -2};
    vector<int> v2 = {5, -3, 5};
    vector<int> v3 = {-3, -2, -3};
    cout << maxSubarraySumCircular(v1) << "\n";
    cout << maxSubarraySumCircular(v2) << "\n";
    cout << maxSubarraySumCircular(v3) << "\n";
    return 0;
}
