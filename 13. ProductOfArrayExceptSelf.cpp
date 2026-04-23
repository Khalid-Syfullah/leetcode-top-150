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

void printVec(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
    cout << "]\n";
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    printVec(productExceptSelf(a));

    vector<int> b = {-1, 1, 0, -3, 3};
    printVec(productExceptSelf(b));

    return 0;
}
