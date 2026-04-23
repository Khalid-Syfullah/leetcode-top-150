public class flattenBinaryTreeToLinkedList {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    private static TreeNode prev;

    public static void flatten(TreeNode root) {
        prev = null;
        reversePreorder(root);
    }

    private static void reversePreorder(TreeNode node) {
        if (node == null) {
            return;
        }

        reversePreorder(node.right);
        reversePreorder(node.left);

        node.right = prev;
        node.left = null;
        prev = node;
    }

    private static void printRightChain(TreeNode root) {
        TreeNode curr = root;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.right != null) {
                System.out.print(" -> ");
            }
            curr = curr.right;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(6);

        flatten(root);
        printRightChain(root);
    }
}
