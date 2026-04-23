#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 1;
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    vector<int> a = {1, 1, 2};
    int ka = removeDuplicates(a);
    cout << "Expected: 2, Got: " << ka << "\n";

    vector<int> b = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int kb = removeDuplicates(b);
    cout << "Expected: 5, Got: " << kb << "\n";

    return 0;
}
