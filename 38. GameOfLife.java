import java.util.Arrays;

public class gameOfLife {

    public static void gameOfLife(int[][] board) {
        int rows = board.length;
        int cols = board[0].length;

        // 8 neighbor directions (row delta and col delta).
        int[] dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        // First pass: compute transitions in-place using encoded values.
        //  1  -> currently alive
        //  0  -> currently dead
        // -1  -> was alive, will become dead
        //  2  -> was dead, will become alive
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int liveNeighbors = 0;

                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                        continue;
                    }

                    // Count cells that were originally alive:
                    // 1 (alive stays/alive decision pending) and -1 (alive -> dead).
                    if (board[nr][nc] == 1 || board[nr][nc] == -1) {
                        liveNeighbors++;
                    }
                }

                // Rule 1 + 3: live cell dies if <2 or >3 live neighbors.
                if (board[r][c] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[r][c] = -1; // live -> dead
                }

                // Rule 4: dead cell becomes live if exactly 3 live neighbors.
                if (board[r][c] == 0 && liveNeighbors == 3) {
                    board[r][c] = 2; // dead -> live
                }
            }
        }

        // Second pass: normalize encoded states back to 0/1.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] > 0) {
                    board[r][c] = 1;
                } else {
                    board[r][c] = 0;
                }
            }
        }
    }

    private static void printBoard(int[][] board) {
        for (int[] row : board) {
            System.out.println(Arrays.toString(row));
        }
    }

    public static void main(String[] args) {
        int[][] board = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
        };

        gameOfLife(board);
        printBoard(board);
    }
}
