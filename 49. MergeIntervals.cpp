#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    vector<int> current = intervals[0];
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] <= current[1]) {
            current[1] = max(current[1], intervals[i][1]);
        } else {
            merged.push_back(current);
            current = intervals[i];
        }
    }
    merged.push_back(current);
    return merged;
}

void print(const vector<vector<int>>& intervals) {
    for (const auto& iv : intervals) {
        cout << "[" << iv[0] << ", " << iv[1] << "]\n";
    }
}

int main() {
    vector<vector<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    print(merge(a));
    cout << "\n";

    vector<vector<int>> b = {{1, 4}, {4, 5}};
    print(merge(b));
}
