#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int num : s) {
        if (!s.count(num - 1)) {
            int current = num, length = 1;
            while (s.count(current + 1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}

int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(a) << "\n";

    vector<int> b = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(b) << "\n";

    vector<int> c = {};
    cout << longestConsecutive(c) << "\n";
}
