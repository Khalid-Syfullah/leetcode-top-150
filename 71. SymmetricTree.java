public class SymmetricTree {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    public static boolean isSymmetric(TreeNode root) {
        return root == null || mirror(root.left, root.right);
    }

    private static boolean mirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        return a.val == b.val && mirror(a.left, b.right) && mirror(a.right, b.left);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);
        System.out.println(isSymmetric(root)); // true

        TreeNode r2 = new TreeNode(1);
        r2.left = new TreeNode(2);
        r2.right = new TreeNode(2);
        r2.left.right = new TreeNode(3);
        r2.right.right = new TreeNode(3);
        System.out.println(isSymmetric(r2)); // false
    }
}
