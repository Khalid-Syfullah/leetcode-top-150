#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int required = prerequisite[1];
        graph[required].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for (int course = 0; course < numCourses; course++) {
        if (indegree[course] == 0) q.push(course);
    }

    vector<int> order;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        order.push_back(current);
        for (int next : graph[current]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    if ((int)order.size() != numCourses) return {};
    return order;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
    cout << "]\n";
}

int main() {
    vector<vector<int>> p1 = {{1, 0}};
    printVector(findOrder(2, p1));
    vector<vector<int>> p2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    printVector(findOrder(4, p2));
    vector<vector<int>> p3 = {};
    printVector(findOrder(1, p3));
    vector<vector<int>> p4 = {{1, 0}, {0, 1}};
    printVector(findOrder(2, p4));
    return 0;
}
