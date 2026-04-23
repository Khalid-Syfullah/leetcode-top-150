/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class cloneGraph3 {

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
    
    public Node cloneGraph(Node node) {

        if (node == null) return null;
        
        Map<Node, Node> visited = new HashMap<>();

        Queue<Node> queue = new LinkedList<>();
        queue.add(node);

        visited.put(node, new Node(node.val));

        while(!queue.isEmpty()){
            Node curr = queue.poll();

            for (Node neighbor: curr.neighbors) {
                if (!visited.containsKey(neighbor)) {         // Not yet cloned
                    visited.put(neighbor, new Node(neighbor.val)); // Clone it
                    queue.add(neighbor);                       // Enqueue for processing
                }
                visited.get(curr).neighbors.add(visited.get(neighbor));
            }
        }

        return visited.get(node);

    }

   
}