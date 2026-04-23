#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, end = 0, far = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        far = max(far, i + nums[i]);
        if (i == end) {
            jumps++;
            end = far;
        }
    }
    return jumps;
}

int main() {
    vector<int> a = {2, 3, 1, 1, 4};
    cout << jump(a) << "\n";

    vector<int> b = {2, 3, 0, 1, 4};
    cout << jump(b) << "\n";

    vector<int> c = {1};
    cout << jump(c) << "\n";

    return 0;
}
