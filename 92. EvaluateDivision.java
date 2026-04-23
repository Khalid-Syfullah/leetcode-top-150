import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EvaluateDivision {

    static class Edge {
        String neighbor;
        double weight;

        Edge(String neighbor, double weight) {
            this.neighbor = neighbor;
            this.weight = weight;
        }
    }

    public static double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Edge>> graph = buildGraph(equations, values);
        double[] result = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {
            String start = queries.get(i).get(0);
            String end = queries.get(i).get(1);

            if (!graph.containsKey(start) || !graph.containsKey(end)) {
                result[i] = -1.0;
                continue;
            }

            if (start.equals(end)) {
                result[i] = 1.0;
                continue;
            }

            result[i] = dfs(start, end, 1.0, graph, new HashMap<>());
        }

        return result;
    }

    private static Map<String, List<Edge>> buildGraph(List<List<String>> equations, double[] values) {
        Map<String, List<Edge>> graph = new HashMap<>();

        for (int i = 0; i < equations.size(); i++) {
            String dividend = equations.get(i).get(0);
            String divisor = equations.get(i).get(1);
            double value = values[i];

            graph.computeIfAbsent(dividend, k -> new ArrayList<>()).add(new Edge(divisor, value));
            graph.computeIfAbsent(divisor, k -> new ArrayList<>()).add(new Edge(dividend, 1.0 / value));
        }

        return graph;
    }

    private static double dfs(
        String current,
        String target,
        double product,
        Map<String, List<Edge>> graph,
        Map<String, Boolean> visited
    ) {
        if (current.equals(target)) {
            return product;
        }

        visited.put(current, true);

        for (Edge edge : graph.getOrDefault(current, new ArrayList<>())) {
            if (visited.containsKey(edge.neighbor)) {
                continue;
            }

            double answer = dfs(edge.neighbor, target, product * edge.weight, graph, visited);
            if (answer != -1.0) {
                return answer;
            }
        }

        return -1.0;
    }

    public static void main(String[] args) {
        List<List<String>> equations1 = List.of(
            List.of("a", "b"),
            List.of("b", "c")
        );
        double[] values1 = {2.0, 3.0};
        List<List<String>> queries1 = List.of(
            List.of("a", "c"),
            List.of("b", "a"),
            List.of("a", "e"),
            List.of("a", "a"),
            List.of("x", "x")
        );

        List<List<String>> equations2 = List.of(
            List.of("a", "b"),
            List.of("b", "c"),
            List.of("bc", "cd")
        );
        double[] values2 = {1.5, 2.5, 5.0};
        List<List<String>> queries2 = List.of(
            List.of("a", "c"),
            List.of("c", "b"),
            List.of("bc", "cd"),
            List.of("cd", "bc")
        );

        System.out.println(java.util.Arrays.toString(calcEquation(equations1, values1, queries1)));
        System.out.println(java.util.Arrays.toString(calcEquation(equations2, values2, queries2)));
    }
}
