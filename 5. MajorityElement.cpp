#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> a = {3, 2, 3};
    cout << majorityElement(a) << "\n";

    vector<int> b = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(b) << "\n";

    vector<int> c = {1};
    cout << majorityElement(c) << "\n";

    return 0;
}
