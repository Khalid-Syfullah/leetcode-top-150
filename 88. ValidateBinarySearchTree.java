class TreeNodeValidate {
    int val;
    TreeNodeValidate left;
    TreeNodeValidate right;

    TreeNodeValidate(int val) {
        this.val = val;
    }
}

class Solution {
    public boolean isValidBST(TreeNodeValidate root) {
        return validate(root, null, null);
    }

    private boolean validate(TreeNodeValidate node, Long low, Long high) {
        if (node == null) {
            return true;
        }

        if ((low != null && node.val <= low) || (high != null && node.val >= high)) {
            return false;
        }

        return validate(node.left, low, (long) node.val)
            && validate(node.right, (long) node.val, high);
    }
}

public class ValidateBinarySearchTree {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeValidate validRoot = new TreeNodeValidate(2);
        validRoot.left = new TreeNodeValidate(1);
        validRoot.right = new TreeNodeValidate(3);

        TreeNodeValidate invalidRoot = new TreeNodeValidate(5);
        invalidRoot.left = new TreeNodeValidate(1);
        invalidRoot.right = new TreeNodeValidate(4);
        invalidRoot.right.left = new TreeNodeValidate(3);
        invalidRoot.right.right = new TreeNodeValidate(6);

        System.out.println(solution.isValidBST(validRoot));
        System.out.println(solution.isValidBST(invalidRoot));
    }
}
