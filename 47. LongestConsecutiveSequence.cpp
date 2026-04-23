#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for (int num : set) {
        if (!set.count(num - 1)) {
            int current = num;
            int length = 1;
            while (set.count(current + 1)) {
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
    vector<int> b = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> c = {};
    cout << longestConsecutive(a) << "\n";
    cout << longestConsecutive(b) << "\n";
    cout << longestConsecutive(c) << "\n";
    return 0;
}
