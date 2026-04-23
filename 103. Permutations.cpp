#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> current;
    backtrack(nums, used, current, result);
    return result;
}

int main() {
    auto print = [](const vector<vector<int>>& res) {
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ", ";
            cout << "[";
            for (size_t j = 0; j < res[i].size(); j++) {
                if (j) cout << ", ";
                cout << res[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    };
    print(permute({1, 2, 3}));
    print(permute({0, 1}));
    print(permute({1}));
    return 0;
}
