#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = (int)intervals.size();
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

void print(const vector<vector<int>>& intervals) {
    for (const auto& iv : intervals) {
        cout << "[" << iv[0] << ", " << iv[1] << "]\n";
    }
}

int main() {
    vector<vector<int>> iv1 = {{1, 3}, {6, 9}};
    vector<int> ni1 = {2, 5};
    print(insert(iv1, ni1));
    cout << "\n";

    vector<vector<int>> iv2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> ni2 = {4, 8};
    print(insert(iv2, ni2));
}
