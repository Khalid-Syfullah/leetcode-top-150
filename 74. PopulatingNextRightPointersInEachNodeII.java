public class populatingNextRightPointersInEachNodeII {

    static class Node {
        int val;
        Node left;
        Node right;
        Node next;

        Node(int val) {
            this.val = val;
        }
    }

    public static Node connect(Node root) {
        Node currentLevel = root;

        while (currentLevel != null) {
            Node dummy = new Node(0);
            Node tail = dummy;

            while (currentLevel != null) {
                if (currentLevel.left != null) {
                    tail.next = currentLevel.left;
                    tail = tail.next;
                }
                if (currentLevel.right != null) {
                    tail.next = currentLevel.right;
                    tail = tail.next;
                }
                currentLevel = currentLevel.next;
            }

            currentLevel = dummy.next;
        }

        return root;
    }

    private static void printByNext(Node root) {
        Node levelStart = root;
        while (levelStart != null) {
            Node curr = levelStart;
            levelStart = null;

            while (curr != null) {
                System.out.print(curr.val + " ");
                if (levelStart == null) {
                    if (curr.left != null) {
                        levelStart = curr.left;
                    } else if (curr.right != null) {
                        levelStart = curr.right;
                    }
                }
                curr = curr.next;
            }
            System.out.println("#");
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(7);

        connect(root);
        printByNext(root);
    }
}
