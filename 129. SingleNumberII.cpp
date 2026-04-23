#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}

int main() {
    vector<int> v1 = {2, 2, 3, 2};
    vector<int> v2 = {0, 1, 0, 1, 0, 1, 99};
    vector<int> v3 = {-2, -2, -2, -7};
    cout << singleNumber(v1) << "\n";
    cout << singleNumber(v2) << "\n";
    cout << singleNumber(v3) << "\n";
    return 0;
}
