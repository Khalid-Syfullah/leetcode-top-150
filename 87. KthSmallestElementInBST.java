import java.util.Stack;

class TreeNodeKth {
    int val;
    TreeNodeKth left;
    TreeNodeKth right;

    TreeNodeKth(int val) {
        this.val = val;
    }
}

class Solution {
    public int kthSmallest(TreeNodeKth root, int k) {
        Stack<TreeNodeKth> stack = new Stack<>();
        TreeNodeKth current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();
            k--;
            if (k == 0) {
                return current.val;
            }

            current = current.right;
        }

        return -1;
    }
}

public class KthSmallestElementInBST {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeKth root1 = new TreeNodeKth(3);
        root1.left = new TreeNodeKth(1);
        root1.right = new TreeNodeKth(4);
        root1.left.right = new TreeNodeKth(2);

        TreeNodeKth root2 = new TreeNodeKth(5);
        root2.left = new TreeNodeKth(3);
        root2.right = new TreeNodeKth(6);
        root2.left.left = new TreeNodeKth(2);
        root2.left.right = new TreeNodeKth(4);
        root2.left.left.left = new TreeNodeKth(1);

        System.out.println(solution.kthSmallest(root1, 1));
        System.out.println(solution.kthSmallest(root2, 3));
    }
}
