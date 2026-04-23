#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v3 = {1};
    cout << search(v1, 0) << "\n";
    cout << search(v2, 3) << "\n";
    cout << search(v3, 0) << "\n";
    return 0;
}
