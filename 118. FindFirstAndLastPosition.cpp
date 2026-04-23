#include <iostream>
#include <vector>
using namespace std;

int findBound(vector<int>& nums, int target, bool isFirst) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            answer = mid;
            if (isFirst) right = mid - 1;
            else left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = findBound(nums, target, true);
    if (first == -1) return {-1, -1};
    int last = findBound(nums, target, false);
    return {first, last};
}

int main() {
    auto print = [](const vector<int>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << v[i];
        }
        cout << "]\n";
    };
    vector<int> v1 = {5, 7, 7, 8, 8, 10};
    vector<int> v2 = {5, 7, 7, 8, 8, 10};
    vector<int> v3 = {};
    print(searchRange(v1, 8));
    print(searchRange(v2, 6));
    print(searchRange(v3, 0));
    return 0;
}
