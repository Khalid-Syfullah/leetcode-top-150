#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int>& nums) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {1, 2, 1, 3, 5, 6, 4};
    vector<int> v3 = {1};
    cout << findPeak(v1) << "\n";
    cout << findPeak(v2) << "\n";
    cout << findPeak(v3) << "\n";
    return 0;
}
