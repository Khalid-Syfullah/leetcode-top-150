class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

class Solution {
    private int maxSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return maxSum;
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;

        int left  = Math.max(dfs(node.left),  0);
        int right = Math.max(dfs(node.right), 0);

        maxSum = Math.max(maxSum, node.val + left + right);

        return node.val + Math.max(left, right);
    }
}

public class MaxPathSum {
    public static void main(String[] args) {
        // Test 1: [-10, 9, 20, null, null, 15, 7] => expected 42
        TreeNode root1 = new TreeNode(-10);
        root1.left  = new TreeNode(9);
        root1.right = new TreeNode(20);
        root1.right.left  = new TreeNode(15);
        root1.right.right = new TreeNode(7);
        System.out.println("Test 1: " + new Solution().maxPathSum(root1)); // 42

        // Test 2: [1, 2, 3] => expected 6
        TreeNode root2 = new TreeNode(1);
        root2.left  = new TreeNode(2);
        root2.right = new TreeNode(3);
        System.out.println("Test 2: " + new Solution().maxPathSum(root2)); // 6

        // Test 3: [-3] => expected -3
        TreeNode root3 = new TreeNode(-3);
        System.out.println("Test 3: " + new Solution().maxPathSum(root3)); // -3
    }
}
