#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
    }
    return true;
}

int main() {
    cout << boolalpha;

    vector<int> a = {2, 3, 1, 1, 4};
    cout << canJump(a) << "\n";

    vector<int> b = {3, 2, 1, 0, 4};
    cout << canJump(b) << "\n";

    vector<int> c = {0};
    cout << canJump(c) << "\n";

    return 0;
}
