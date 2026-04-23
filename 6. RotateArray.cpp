#include <iostream>
#include <vector>
using namespace std;

void reverseArr(vector<int>& nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverseArr(nums, 0, n - 1);
    reverseArr(nums, 0, k - 1);
    reverseArr(nums, k, n - 1);
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums1, 3);
    cout << "Expected: [5, 6, 7, 1, 2, 3, 4]" << "\n";
    cout << "Actual:   [";
    for (int i = 0; i < (int)nums1.size(); i++) { if (i) cout << ", "; cout << nums1[i]; }
    cout << "]\n";

    vector<int> nums2 = {-1, -100, 3, 99};
    rotate(nums2, 2);
    cout << "Expected: [3, 99, -1, -100]" << "\n";
    cout << "Actual:   [";
    for (int i = 0; i < (int)nums2.size(); i++) { if (i) cout << ", "; cout << nums2[i]; }
    cout << "]\n";

    vector<int> nums3 = {1, 2};
    rotate(nums3, 5);
    cout << "Expected: [2, 1]" << "\n";
    cout << "Actual:   [";
    for (int i = 0; i < (int)nums3.size(); i++) { if (i) cout << ", "; cout << nums3[i]; }
    cout << "]\n";

    return 0;
}
