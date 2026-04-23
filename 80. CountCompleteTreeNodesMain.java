class TreeNodeCount {
    int val;
    TreeNodeCount left;
    TreeNodeCount right;

    TreeNodeCount(int val) {
        this.val = val;
    }
}

class CountCompleteTreeNodesSolution {
    public int countNodes(TreeNodeCount root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    private int getLeftHeight(TreeNodeCount node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.left;
        }
        return height;
    }

    private int getRightHeight(TreeNodeCount node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.right;
        }
        return height;
    }
}

public class CountCompleteTreeNodesMain {
    public static void main(String[] args) {
        // Complete tree: [1,2,3,4,5,6]
        TreeNodeCount root = new TreeNodeCount(1);
        root.left = new TreeNodeCount(2);
        root.right = new TreeNodeCount(3);
        root.left.left = new TreeNodeCount(4);
        root.left.right = new TreeNodeCount(5);
        root.right.left = new TreeNodeCount(6);

        CountCompleteTreeNodesSolution solution = new CountCompleteTreeNodesSolution();
        System.out.println(solution.countNodes(root));
    }
}
