#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        auto it = seen.find(target - nums[i]);
        if (it != seen.end()) return {it->second, i};
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> a = {2, 7, 11, 15};
    auto r1 = twoSum(a, 9);
    cout << "[" << r1[0] << ", " << r1[1] << "]\n";

    vector<int> b = {3, 2, 4};
    auto r2 = twoSum(b, 6);
    cout << "[" << r2[0] << ", " << r2[1] << "]\n";

    vector<int> c = {3, 3};
    auto r3 = twoSum(c, 6);
    cout << "[" << r3[0] << ", " << r3[1] << "]\n";
}
