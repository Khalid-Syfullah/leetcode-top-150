import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class SnakesAndLadders {

    public static int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[] flat = new int[n * n + 1];
        int idx = 1;
        boolean leftToRight = true;
        for (int r = n - 1; r >= 0; r--) {
            if (leftToRight) {
                for (int c = 0; c < n; c++) flat[idx++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--) flat[idx++] = board[r][c];
            }
            leftToRight = !leftToRight;
        }
        int[] dist = new int[n * n + 1];
        Arrays.fill(dist, -1);
        dist[1] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == n * n) return dist[cur];
            for (int next = cur + 1; next <= Math.min(cur + 6, n * n); next++) {
                int dest = flat[next] == -1 ? next : flat[next];
                if (dist[dest] == -1) {
                    dist[dest] = dist[cur] + 1;
                    q.offer(dest);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[][] board = {
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 35, -1, -1, 13, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 15, -1, -1, -1, -1}
        };
        System.out.println(snakesAndLadders(board)); // 4
        System.out.println(snakesAndLadders(new int[][]{{-1, -1}, {-1, 3}})); // 1
    }
}
