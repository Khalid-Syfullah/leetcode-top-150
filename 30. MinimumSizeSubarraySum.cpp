#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, sum = 0, best = INT_MAX;
    for (int r = 0; r < (int)nums.size(); r++) {
        sum += nums[r];
        while (sum >= target) {
            best = min(best, r - l + 1);
            sum -= nums[l++];
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main() {
    vector<int> a = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, a) << "\n";

    vector<int> b = {1, 4, 4};
    cout << minSubArrayLen(4, b) << "\n";

    vector<int> c = {1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, c) << "\n";
}
