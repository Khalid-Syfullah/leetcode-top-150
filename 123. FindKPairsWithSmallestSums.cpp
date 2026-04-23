#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k == 0) return result;
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        return a[0] + a[1] > b[0] + b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
    for (int i = 0; i < (int)min((int)nums1.size(), k); i++) {
        minHeap.push({nums1[i], nums2[0], 0});
    }
    while (k > 0 && !minHeap.empty()) {
        vector<int> curr = minHeap.top();
        minHeap.pop();
        int first = curr[0];
        int second = curr[1];
        int j = curr[2];
        result.push_back({first, second});
        if (j + 1 < (int)nums2.size()) {
            minHeap.push({first, nums2[j + 1], j + 1});
        }
        k--;
    }
    return result;
}

int main() {
    auto print = [](const vector<vector<int>>& res) {
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ", ";
            cout << "[" << res[i][0] << ", " << res[i][1] << "]";
        }
        cout << "]\n";
    };
    vector<int> n1 = {1, 7, 11}, n2 = {2, 4, 6};
    vector<int> n3 = {1, 1, 2}, n4 = {1, 2, 3};
    print(kSmallestPairs(n1, n2, 3));
    print(kSmallestPairs(n3, n4, 2));
    return 0;
}
