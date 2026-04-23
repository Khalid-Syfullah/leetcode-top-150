import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNodeLevelOrder {
    int val;
    TreeNodeLevelOrder left;
    TreeNodeLevelOrder right;

    TreeNodeLevelOrder(int val) {
        this.val = val;
    }
}

class Solution {
    public List<List<Integer>> levelOrder(TreeNodeLevelOrder root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Queue<TreeNodeLevelOrder> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < levelSize; i++) {
                TreeNodeLevelOrder node = queue.poll();
                level.add(node.val);

                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            result.add(level);
        }

        return result;
    }
}

public class BinaryTreeLevelOrderTraversal {
    public static void main(String[] args) {
        Solution solution = new Solution();

        TreeNodeLevelOrder root = new TreeNodeLevelOrder(3);
        root.left = new TreeNodeLevelOrder(9);
        root.right = new TreeNodeLevelOrder(20);
        root.right.left = new TreeNodeLevelOrder(15);
        root.right.right = new TreeNodeLevelOrder(7);

        System.out.println(solution.levelOrder(root));
        System.out.println(solution.levelOrder(null));
    }
}
