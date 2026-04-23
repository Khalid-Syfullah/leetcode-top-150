#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main() {
    vector<int> v1 = {1, 3, 5, 6};
    cout << searchInsert(v1, 5) << "\n";
    cout << searchInsert(v1, 2) << "\n";
    cout << searchInsert(v1, 7) << "\n";
    cout << searchInsert(v1, 0) << "\n";
    return 0;
}
