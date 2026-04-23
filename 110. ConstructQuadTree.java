public class constructQuadTree {

    static class Node {
        public boolean val;
        public boolean isLeaf;
        public Node topLeft;
        public Node topRight;
        public Node bottomLeft;
        public Node bottomRight;

        public Node() {}

        public Node(boolean val, boolean isLeaf) {
            this.val = val;
            this.isLeaf = isLeaf;
        }

        public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
            this.val = val;
            this.isLeaf = isLeaf;
            this.topLeft = topLeft;
            this.topRight = topRight;
            this.bottomLeft = bottomLeft;
            this.bottomRight = bottomRight;
        }
    }

    public static Node construct(int[][] grid) {
        return build(grid, 0, 0, grid.length);
    }

    private static Node build(int[][] grid, int row, int col, int size) {
        if (isUniform(grid, row, col, size)) {
            return new Node(grid[row][col] == 1, true);
        }

        int half = size / 2;
        Node topLeft = build(grid, row, col, half);
        Node topRight = build(grid, row, col + half, half);
        Node bottomLeft = build(grid, row + half, col, half);
        Node bottomRight = build(grid, row + half, col + half, half);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    private static boolean isUniform(int[][] grid, int row, int col, int size) {
        int value = grid[row][col];
        for (int r = row; r < row + size; r++) {
            for (int c = col; c < col + size; c++) {
                if (grid[r][c] != value) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void printPreorder(Node root) {
        if (root == null) {
            return;
        }
        if (root.isLeaf) {
            System.out.print("[Leaf:" + (root.val ? 1 : 0) + "] ");
            return;
        }

        System.out.print("[Parent] ");
        printPreorder(root.topLeft);
        printPreorder(root.topRight);
        printPreorder(root.bottomLeft);
        printPreorder(root.bottomRight);
    }

    public static void main(String[] args) {
        int[][] grid = {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {1, 1, 0, 0}
        };

        Node root = construct(grid);
        printPreorder(root);
        System.out.println();
    }
}
