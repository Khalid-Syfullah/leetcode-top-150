#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> v1 = {2, 2, 1};
    vector<int> v2 = {4, 1, 2, 1, 2};
    vector<int> v3 = {1};
    cout << singleNumber(v1) << "\n";
    cout << singleNumber(v2) << "\n";
    cout << singleNumber(v3) << "\n";
    return 0;
}
