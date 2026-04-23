#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> out;
    int i = 0, n = (int)nums.size();
    while (i < n) {
        int start = nums[i];
        while (i + 1 < n && nums[i + 1] == nums[i] + 1) i++;
        if (start == nums[i]) out.push_back(to_string(start));
        else out.push_back(to_string(start) + "->" + to_string(nums[i]));
        i++;
    }
    return out;
}

int main() {
    auto print = [](vector<string> v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
        cout << "]\n";
    };
    vector<int> a = {0, 1, 2, 4, 5, 7};
    vector<int> b = {0, 2, 3, 4, 6, 8, 9};
    vector<int> c = {};
    print(summaryRanges(a));
    print(summaryRanges(b));
    print(summaryRanges(c));
    return 0;
}
