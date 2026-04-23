public class sumRootToLeafNumbers2 {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    public static int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private static int dfs(TreeNode node, int current) {
        if (node == null) {
            return 0;
        }

        int value = current * 10 + node.val;

        if (node.left == null && node.right == null) {
            return value;
        }

        return dfs(node.left, value) + dfs(node.right, value);
    }

    public static void main(String[] args) {
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        // Paths: 124 + 125 + 13 = 262
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.println("Sum: " + sumNumbers(root));
    }
}
