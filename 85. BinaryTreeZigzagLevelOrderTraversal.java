import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNodeZigzag {
    int val;
    TreeNodeZigzag left;
    TreeNodeZigzag right;

    TreeNodeZigzag(int val) {
        this.val = val;
    }
}

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNodeZigzag root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNodeZigzag> queue = new LinkedList<>();
        queue.offer(root);
        boolean leftToRight = true;

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            LinkedList<Integer> level = new LinkedList<>();

            for (int i = 0; i < levelSize; i++) {
                TreeNodeZigzag node = queue.poll();

                if (leftToRight) {
                    level.addLast(node.val);
                } else {
                    level.addFirst(node.val);
                }

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            result.add(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
}

public class BinaryTreeZigzagLevelOrderTraversal {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeZigzag root = new TreeNodeZigzag(3);
        root.left = new TreeNodeZigzag(9);
        root.right = new TreeNodeZigzag(20);
        root.right.left = new TreeNodeZigzag(15);
        root.right.right = new TreeNodeZigzag(7);

        System.out.println(solution.zigzagLevelOrder(root));
        System.out.println(solution.zigzagLevelOrder(null));
    }
}
