class TreeNodeLCA {
    int val;
    TreeNodeLCA left;
    TreeNodeLCA right;

    TreeNodeLCA(int val) {
        this.val = val;
    }
}

class Solution {
    public TreeNodeLCA lowestCommonAncestor(TreeNodeLCA root, TreeNodeLCA p, TreeNodeLCA q) {
        if (root == null || root == p || root == q) {
            return root;
        }

        TreeNodeLCA left = lowestCommonAncestor(root.left, p, q);
        TreeNodeLCA right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }

        return left != null ? left : right;
    }
}

public class LowestCommonAncestorBinaryTree {
    public static void main(String[] args) {
        TreeNodeLCA root = new TreeNodeLCA(3);
        root.left = new TreeNodeLCA(5);
        root.right = new TreeNodeLCA(1);
        root.left.left = new TreeNodeLCA(6);
        root.left.right = new TreeNodeLCA(2);
        root.right.left = new TreeNodeLCA(0);
        root.right.right = new TreeNodeLCA(8);
        root.left.right.left = new TreeNodeLCA(7);
        root.left.right.right = new TreeNodeLCA(4);

        Solution solution = new Solution();

        TreeNodeLCA lca1 = solution.lowestCommonAncestor(root, root.left, root.right);
        TreeNodeLCA lca2 = solution.lowestCommonAncestor(root, root.left, root.left.right.right);

        System.out.println(lca1.val);
        System.out.println(lca2.val);
    }
}
