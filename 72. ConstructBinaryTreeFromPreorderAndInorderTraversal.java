import java.util.HashMap;
import java.util.Map;

public class constructBinaryTreeFromPreorderAndInorderTraversal {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    private static int preorderIndex;
    private static Map<Integer, Integer> inorderPos;

    public static TreeNode buildTree(int[] preorder, int[] inorder) {
        preorderIndex = 0;
        inorderPos = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            inorderPos.put(inorder[i], i);
        }

        return build(preorder, 0, inorder.length - 1);
    }

    private static TreeNode build(int[] preorder, int left, int right) {
        if (left > right) {
            return null;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode root = new TreeNode(rootVal);

        int mid = inorderPos.get(rootVal);
        root.left = build(preorder, left, mid - 1);
        root.right = build(preorder, mid + 1, right);

        return root;
    }

    private static void printInorder(TreeNode root) {
        if (root == null) {
            return;
        }
        printInorder(root.left);
        System.out.print(root.val + " ");
        printInorder(root.right);
    }

    private static void printPreorder(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.print(root.val + " ");
        printPreorder(root.left);
        printPreorder(root.right);
    }

    public static void main(String[] args) {
        int[] preorder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};

        TreeNode root = buildTree(preorder, inorder);

        printPreorder(root);
        System.out.println();
        printInorder(root);
        System.out.println();
    }
}
