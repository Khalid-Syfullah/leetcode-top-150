#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> last;
    for (int i = 0; i < (int)nums.size(); i++) {
        auto it = last.find(nums[i]);
        if (it != last.end() && i - it->second <= k) return true;
        last[nums[i]] = i;
    }
    return false;
}

int main() {
    cout << boolalpha;
    vector<int> a = {1, 2, 3, 1};
    vector<int> b = {1, 0, 1, 1};
    vector<int> c = {1, 2, 3, 1, 2, 3};
    cout << containsNearbyDuplicate(a, 3) << "\n";
    cout << containsNearbyDuplicate(b, 1) << "\n";
    cout << containsNearbyDuplicate(c, 2) << "\n";
    return 0;
}
