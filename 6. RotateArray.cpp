#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
    cout << "]";
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums1, 3);
    cout << "Expected: [5, 6, 7, 1, 2, 3, 4]\n";
    cout << "Actual:   "; printVec(nums1); cout << "\n";

    vector<int> nums2 = {-1, -100, 3, 99};
    rotate(nums2, 2);
    cout << "Expected: [3, 99, -1, -100]\n";
    cout << "Actual:   "; printVec(nums2); cout << "\n";

    vector<int> nums3 = {1, 2};
    rotate(nums3, 5);
    cout << "Expected: [2, 1]\n";
    cout << "Actual:   "; printVec(nums3); cout << "\n";

    return 0;
}
