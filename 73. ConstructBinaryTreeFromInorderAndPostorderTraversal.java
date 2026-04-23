import java.util.HashMap;
import java.util.Map;

public class constructBinaryTreeFromInorderAndPostorderTraversal {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    private static int postIndex;
    private static Map<Integer, Integer> inorderPos;

    public static TreeNode buildTree(int[] inorder, int[] postorder) {
        inorderPos = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderPos.put(inorder[i], i);
        }

        postIndex = postorder.length - 1;
        return build(inorder, postorder, 0, inorder.length - 1);
    }

    private static TreeNode build(int[] inorder, int[] postorder, int left, int right) {
        if (left > right) {
            return null;
        }

        int rootVal = postorder[postIndex--];
        TreeNode root = new TreeNode(rootVal);

        int mid = inorderPos.get(rootVal);

        // Build right first because we consume postorder from the end.
        root.right = build(inorder, postorder, mid + 1, right);
        root.left = build(inorder, postorder, left, mid - 1);

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

    private static void printPostorder(TreeNode root) {
        if (root == null) {
            return;
        }
        printPostorder(root.left);
        printPostorder(root.right);
        System.out.print(root.val + " ");
    }

    public static void main(String[] args) {
        int[] inorder = {9, 3, 15, 20, 7};
        int[] postorder = {9, 15, 7, 20, 3};

        TreeNode root = buildTree(inorder, postorder);

        printInorder(root);
        System.out.println();
        printPostorder(root);
        System.out.println();
    }
}
