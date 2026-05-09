#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int snakesAndLadders(int board[][6], int n) {
    /* Flatten board into 1-indexed flat array */
    int flat[37];  /* n*n <= 36 for n=6 */
    int idx = 1;
    int leftToRight = 1;
    for (int r = n - 1; r >= 0; r--) {
        if (leftToRight) {
            for (int c = 0; c < n; c++) flat[idx++] = board[r][c];
        } else {
            for (int c = n - 1; c >= 0; c--) flat[idx++] = board[r][c];
        }
        leftToRight = !leftToRight;
    }

    int dist[37];
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;

    int queue[37];
    int head = 0, tail = 0;
    queue[tail++] = 1;

    while (head < tail) {
        int cur = queue[head++];
        if (cur == n * n) return dist[cur];
        int limit = cur + 6 < n * n ? cur + 6 : n * n;
        for (int next = cur + 1; next <= limit; next++) {
            int dest = flat[next] == -1 ? next : flat[next];
            if (dist[dest] == -1) {
                dist[dest] = dist[cur] + 1;
                queue[tail++] = dest;
            }
        }
    }
    return -1;
}

int main(void) {
    int board1[6][6] = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    printf("%d\n", snakesAndLadders(board1, 6)); // 4

    /* Second test: 2x2 board {{-1,-1},{-1,3}} */
    /* Need a separate function or workaround for different n.
       We'll inline the logic for n=2. */
    {
        int n = 2;
        int flat[5];
        int id = 1;
        int ltr = 1;
        int b2[2][2] = {{-1,-1},{-1,3}};
        for (int r = n - 1; r >= 0; r--) {
            if (ltr) {
                for (int c = 0; c < n; c++) flat[id++] = b2[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--) flat[id++] = b2[r][c];
            }
            ltr = !ltr;
        }
        int dist[5];
        memset(dist, -1, sizeof(dist));
        dist[1] = 0;
        int q[5]; int hd = 0, tl = 0;
        q[tl++] = 1;
        int ans = -1;
        while (hd < tl) {
            int cur = q[hd++];
            if (cur == n * n) { ans = dist[cur]; break; }
            int lim = cur + 6 < n * n ? cur + 6 : n * n;
            for (int nx = cur + 1; nx <= lim; nx++) {
                int dest = flat[nx] == -1 ? nx : flat[nx];
                if (dist[dest] == -1) {
                    dist[dest] = dist[cur] + 1;
                    q[tl++] = dest;
                }
            }
        }
        printf("%d\n", ans); // 1
    }
    return 0;
}
