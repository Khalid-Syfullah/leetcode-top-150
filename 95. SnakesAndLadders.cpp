#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> flat(n * n + 1);
    int idx = 1;
    bool leftToRight = true;
    for (int r = n - 1; r >= 0; r--) {
        if (leftToRight) {
            for (int c = 0; c < n; c++) flat[idx++] = board[r][c];
        } else {
            for (int c = n - 1; c >= 0; c--) flat[idx++] = board[r][c];
        }
        leftToRight = !leftToRight;
    }
    vector<int> dist(n * n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n * n) return dist[cur];
        for (int next = cur + 1; next <= min(cur + 6, n * n); next++) {
            int dest = flat[next] == -1 ? next : flat[next];
            if (dist[dest] == -1) {
                dist[dest] = dist[cur] + 1;
                q.push(dest);
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    cout << snakesAndLadders(board) << "\n";
    vector<vector<int>> board2 = {{-1,-1},{-1,3}};
    cout << snakesAndLadders(board2) << "\n";
    return 0;
}
