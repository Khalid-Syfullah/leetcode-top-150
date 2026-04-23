public class SameTree {

    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int val) { this.val = val; }
    }

    public static boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public static void main(String[] args) {
        TreeNode a = new TreeNode(1); a.left = new TreeNode(2); a.right = new TreeNode(3);
        TreeNode b = new TreeNode(1); b.left = new TreeNode(2); b.right = new TreeNode(3);
        System.out.println(isSameTree(a, b)); // true

        TreeNode c = new TreeNode(1); c.left = new TreeNode(2);
        TreeNode d = new TreeNode(1); d.right = new TreeNode(2);
        System.out.println(isSameTree(c, d)); // false
    }
}
