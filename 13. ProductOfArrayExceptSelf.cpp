#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> ra = productExceptSelf(a);
    for (int i = 0; i < (int)ra.size(); i++) { if (i) cout << ", "; cout << ra[i]; } cout << "\n";

    vector<int> b = {-1, 1, 0, -3, 3};
    vector<int> rb = productExceptSelf(b);
    for (int i = 0; i < (int)rb.size(); i++) { if (i) cout << ", "; cout << rb[i]; } cout << "\n";

    return 0;
}
