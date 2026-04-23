#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = (int)numbers.size() - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) return {l + 1, r + 1};
        if (sum < target) l++; else r--;
    }
    return {-1, -1};
}

int main() {
    vector<int> a = {2, 7, 11, 15};
    vector<int> r1 = twoSum(a, 9);
    cout << "[" << r1[0] << ", " << r1[1] << "]\n";

    vector<int> b = {2, 3, 4};
    vector<int> r2 = twoSum(b, 6);
    cout << "[" << r2[0] << ", " << r2[1] << "]\n";

    vector<int> c = {-1, 0};
    vector<int> r3 = twoSum(c, -1);
    cout << "[" << r3[0] << ", " << r3[1] << "]\n";
}
