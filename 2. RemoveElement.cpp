#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int n : nums) {
        if (n != val) nums[k++] = n;
    }
    return k;
}

int main() {
    vector<int> a = {3, 2, 2, 3};
    cout << removeElement(a, 3) << "\n";

    vector<int> b = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << removeElement(b, 2) << "\n";

    vector<int> c = {};
    cout << removeElement(c, 1) << "\n";

    return 0;
}
