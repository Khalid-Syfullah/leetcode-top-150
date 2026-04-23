#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (int n : nums) {
        if (k < 2 || n != nums[k - 2]) nums[k++] = n;
    }
    return k;
}

int main() {
    vector<int> a = {1, 1, 1, 2, 2, 3};
    cout << removeDuplicates(a) << "\n";

    vector<int> b = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(b) << "\n";

    vector<int> c = {1};
    cout << removeDuplicates(c) << "\n";

    return 0;
}
