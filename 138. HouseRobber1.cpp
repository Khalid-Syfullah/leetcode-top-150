#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = (int)nums.size();
    int prev2 = 0;
    int prev1 = 0;
    for (int i = 0; i < n; i++) {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {2, 7, 9, 3, 1};
    vector<int> v3 = {2};
    vector<int> v4 = {};
    vector<int> v5 = {6, 6, 4, 8, 4, 3, 3, 10};
    cout << rob(v1) << "\n";
    cout << rob(v2) << "\n";
    cout << rob(v3) << "\n";
    cout << rob(v4) << "\n";
    cout << rob(v5) << "\n";
    return 0;
}
