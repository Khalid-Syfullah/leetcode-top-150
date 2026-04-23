#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> out;
    sort(nums.begin(), nums.end());
    int n = (int)nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                out.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++; r--;
            } else if (sum < 0) l++;
            else r--;
        }
    }
    return out;
}

int main() {
    auto print = [](const vector<vector<int>>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << "[";
            for (size_t j = 0; j < v[i].size(); j++) {
                if (j) cout << ", ";
                cout << v[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    };

    vector<int> a = {-1, 0, 1, 2, -1, -4};
    print(threeSum(a));

    vector<int> b = {0, 1, 1};
    print(threeSum(b));

    vector<int> c = {0, 0, 0};
    print(threeSum(c));
}
