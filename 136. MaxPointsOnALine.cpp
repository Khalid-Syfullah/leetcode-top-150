#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a == 0 ? 1 : a;
}

int maxPoints(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    if (points.size() <= 2) return (int)points.size();

    int globalMax = 1;

    for (int i = 0; i < (int)points.size(); i++) {
        unordered_map<string, int> slopeCount;
        int duplicates = 0;
        int localMax = 0;

        for (int j = i + 1; j < (int)points.size(); j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            }

            string key = to_string(dy) + "/" + to_string(dx);
            int count = ++slopeCount[key];
            localMax = max(localMax, count);
        }

        globalMax = max(globalMax, localMax + duplicates + 1);
    }

    return globalMax;
}

int main() {
    vector<vector<int>> points1 = {{1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> points2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << maxPoints(points1) << "\n";
    cout << maxPoints(points2) << "\n";
    return 0;
}
