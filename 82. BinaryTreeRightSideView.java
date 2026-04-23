import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNodeRightView {
    int val;
    TreeNodeRightView left;
    TreeNodeRightView right;

    TreeNodeRightView(int val) {
        this.val = val;
    }
}

class Solution {
    public List<Integer> rightSideView(TreeNodeRightView root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNodeRightView> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNodeRightView node = queue.poll();

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }

                if (i == levelSize - 1) {
                    result.add(node.val);
                }
            }
        }

        return result;
    }
}

public class BinaryTreeRightSideView {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeRightView root1 = new TreeNodeRightView(1);
        root1.left = new TreeNodeRightView(2);
        root1.right = new TreeNodeRightView(3);
        root1.left.right = new TreeNodeRightView(5);
        root1.right.right = new TreeNodeRightView(4);

        TreeNodeRightView root2 = new TreeNodeRightView(1);
        root2.right = new TreeNodeRightView(3);

        System.out.println(solution.rightSideView(root1));
        System.out.println(solution.rightSideView(root2));
        System.out.println(solution.rightSideView(null));
    }
}
