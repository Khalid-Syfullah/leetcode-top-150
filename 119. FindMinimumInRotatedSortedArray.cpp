#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

int main() {
    vector<int> v1 = {3, 4, 5, 1, 2};
    vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v3 = {11, 13, 15, 17};
    cout << findMin(v1) << "\n";
    cout << findMin(v2) << "\n";
    cout << findMin(v3) << "\n";
    return 0;
}
