#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

    int completed = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        completed++;
        for (int next : graph[current]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    return completed == numCourses;
}

int main() {
    cout << boolalpha;
    vector<vector<int>> p1 = {{1, 0}};
    cout << canFinish(2, p1) << "\n";
    vector<vector<int>> p2 = {{1, 0}, {0, 1}};
    cout << canFinish(2, p2) << "\n";
    vector<vector<int>> p3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << canFinish(4, p3) << "\n";
    return 0;
}
