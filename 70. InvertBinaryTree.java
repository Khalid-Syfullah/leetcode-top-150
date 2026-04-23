public class InvertBinaryTree {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    public static TreeNode invertTree(TreeNode root) {
        if (root == null) return null;
        TreeNode l = invertTree(root.left);
        TreeNode r = invertTree(root.right);
        root.left = r;
        root.right = l;
        return root;
    }

    private static void inorder(TreeNode n, StringBuilder sb) {
        if (n == null) return;
        inorder(n.left, sb);
        sb.append(n.val).append(' ');
        inorder(n.right, sb);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);
        invertTree(root);
        StringBuilder sb = new StringBuilder();
        inorder(root, sb);
        System.out.println(sb.toString().trim()); // 9 7 6 4 3 2 1
    }
}
