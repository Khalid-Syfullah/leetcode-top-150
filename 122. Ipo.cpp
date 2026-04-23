#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int,int>> projects(n);
    for (int i = 0; i < n; i++) {
        projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end());
    priority_queue<int> maxHeap;
    int currentCapital = w;
    int index = 0;
    for (int i = 0; i < k; i++) {
        while (index < n && projects[index].first <= currentCapital) {
            maxHeap.push(projects[index].second);
            index++;
        }
        if (maxHeap.empty()) break;
        currentCapital += maxHeap.top();
        maxHeap.pop();
    }
    return currentCapital;
}

int main() {
    vector<int> p1 = {1, 2, 3}, c1 = {0, 1, 1};
    vector<int> p2 = {1, 2, 3}, c2 = {0, 1, 2};
    cout << findMaximizedCapital(2, 0, p1, c1) << "\n";
    cout << findMaximizedCapital(3, 0, p2, c2) << "\n";
    return 0;
}
