#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    if ((int)current.size() == k) {
        result.push_back(current);
        return;
    }
    for (int num = start; num <= n; num++) {
        current.push_back(num);
        backtrack(num + 1, n, k, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(1, n, k, current, result);
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
    print(combine(4, 2));
    print(combine(1, 1));
    return 0;
}
