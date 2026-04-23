#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& result) {
    if (remain == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < (int)candidates.size(); i++) {
        int value = candidates[i];
        if (value > remain) break;
        current.push_back(value);
        backtrack(candidates, remain - value, i, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
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
    print(combinationSum({2, 3, 6, 7}, 7));
    print(combinationSum({2, 3, 5}, 8));
    print(combinationSum({2}, 1));
    return 0;
}
