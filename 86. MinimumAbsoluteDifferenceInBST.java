class TreeNodeMinDiff {
    int val;
    TreeNodeMinDiff left;
    TreeNodeMinDiff right;

    TreeNodeMinDiff(int val) {
        this.val = val;
    }
}

class Solution {
    private Integer prev;
    private int minDiff;

    public int getMinimumDifference(TreeNodeMinDiff root) {
        prev = null;
        minDiff = Integer.MAX_VALUE;
        inorder(root);
        return minDiff;
    }

    private void inorder(TreeNodeMinDiff node) {
        if (node == null) {
            return;
        }

        inorder(node.left);

        if (prev != null) {
            minDiff = Math.min(minDiff, node.val - prev);
        }
        prev = node.val;

        inorder(node.right);
    }
}

public class MinimumAbsoluteDifferenceInBST {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeMinDiff root1 = new TreeNodeMinDiff(4);
        root1.left = new TreeNodeMinDiff(2);
        root1.right = new TreeNodeMinDiff(6);
        root1.left.left = new TreeNodeMinDiff(1);
        root1.left.right = new TreeNodeMinDiff(3);

        TreeNodeMinDiff root2 = new TreeNodeMinDiff(1);
        root2.right = new TreeNodeMinDiff(3);
        root2.right.left = new TreeNodeMinDiff(2);

        System.out.println(solution.getMinimumDifference(root1));
        System.out.println(solution.getMinimumDifference(root2));
    }
}
