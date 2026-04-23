#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int arrows = 1;
    int arrowPos = points[0][1];
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i][0] > arrowPos) {
            arrows++;
            arrowPos = points[i][1];
        }
    }
    return arrows;
}

int main() {
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};
    vector<vector<int>> points3 = {{1,2},{2,3},{3,4},{4,5}};
    cout << findMinArrowShots(points1) << "\n";
    cout << findMinArrowShots(points2) << "\n";
    cout << findMinArrowShots(points3) << "\n";
    return 0;
}
