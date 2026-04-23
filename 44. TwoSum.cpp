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
    auto print = [](vector<int> v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
        cout << "]\n";
    };
    vector<int> a = {2, 7, 11, 15};
    vector<int> b = {3, 2, 4};
    vector<int> c = {3, 3};
    print(twoSum(a, 9));
    print(twoSum(b, 6));
    print(twoSum(c, 6));
    return 0;
}
