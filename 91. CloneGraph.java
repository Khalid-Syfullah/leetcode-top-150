import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class cloneGraph {

    static class Node {
        public int val;
        public List<Node> neighbors;

        public Node() {
            val = 0;
            neighbors = new ArrayList<>();
        }

        public Node(int val) {
            this.val = val;
            neighbors = new ArrayList<>();
        }

        public Node(int val, List<Node> neighbors) {
            this.val = val;
            this.neighbors = neighbors;
        }
    }

    public static Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        return dfs(node, new HashMap<>());
    }

    private static Node dfs(Node node, Map<Node, Node> clones) {
        if (clones.containsKey(node)) {
            return clones.get(node);
        }

        Node copy = new Node(node.val);
        clones.put(node, copy);

        for (Node neighbor : node.neighbors) {
            copy.neighbors.add(dfs(neighbor, clones));
        }

        return copy;
    }

    private static void printGraph(Node node) {
        Map<Node, Boolean> visited = new HashMap<>();
        printDfs(node, visited);
    }

    private static void printDfs(Node node, Map<Node, Boolean> visited) {
        if (node == null || visited.containsKey(node)) {
            return;
        }
        visited.put(node, true);

        System.out.print("Node " + node.val + " -> ");
        for (Node n : node.neighbors) {
            System.out.print(n.val + " ");
        }
        System.out.println();

        for (Node n : node.neighbors) {
            printDfs(n, visited);
        }
    }

    public static void main(String[] args) {
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(4);

        n1.neighbors.add(n2);
        n1.neighbors.add(n4);
        n2.neighbors.add(n1);
        n2.neighbors.add(n3);
        n3.neighbors.add(n2);
        n3.neighbors.add(n4);
        n4.neighbors.add(n1);
        n4.neighbors.add(n3);

        Node clone = cloneGraph(n1);

        printGraph(n1);
        System.out.println("---");
        printGraph(clone);
    }
}
