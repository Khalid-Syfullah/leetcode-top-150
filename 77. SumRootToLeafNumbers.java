public class sumRootToLeafNumbers {

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
        //       4
        //      / \
        //     9   0
        //    / \
        //   5   1
        // Paths: 495 + 491 + 40 = 1026
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(9);
        root.right = new TreeNode(0);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(1);

        System.out.println("Sum: " + sumNumbers(root));
    }
}
