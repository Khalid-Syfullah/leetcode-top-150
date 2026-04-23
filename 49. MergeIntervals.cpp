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
        auto& next = intervals[i];
        if (next[0] <= current[1]) {
            current[1] = max(current[1], next[1]);
        } else {
            merged.push_back(current);
            current = next;
        }
    }
    merged.push_back(current);
    return merged;
}

void print(vector<vector<int>>& intervals) {
    for (auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }
}

int main() {
    vector<vector<int>> a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> b = {{1, 4}, {4, 5}};
    auto ra = merge(a);
    auto rb = merge(b);
    print(ra);
    cout << "\n";
    print(rb);
    return 0;
}
