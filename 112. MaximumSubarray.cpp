#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0];
    int bestSum = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        bestSum = max(bestSum, currentSum);
    }
    return bestSum;
}

int main() {
    vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v2 = {1};
    vector<int> v3 = {5, 4, -1, 7, 8};
    cout << maxSubArray(v1) << "\n";
    cout << maxSubArray(v2) << "\n";
    cout << maxSubArray(v3) << "\n";
    return 0;
}
