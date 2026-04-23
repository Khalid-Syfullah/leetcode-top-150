#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1, best = 0;
    while (l < r) {
        int h = min(height[l], height[r]);
        best = max(best, h * (r - l));
        if (height[l] < height[r]) l++; else r--;
    }
    return best;
}

int main() {
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(a) << "\n";

    vector<int> b = {1, 1};
    cout << maxArea(b) << "\n";
}
