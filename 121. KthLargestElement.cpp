#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> v1 = {3, 2, 1, 5, 6, 4};
    vector<int> v2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(v1, 2) << "\n";
    cout << findKthLargest(v2, 4) << "\n";
    return 0;
}
