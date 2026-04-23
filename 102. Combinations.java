import java.util.ArrayList;
import java.util.List;

public class combinations {

    public static List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1, n, k, new ArrayList<>(), result);
        return result;
    }

    private static void backtrack(int start, int n, int k, List<Integer> current, List<List<Integer>> result) {
        if (current.size() == k) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int num = start; num <= n; num++) {
            current.add(num);
            backtrack(num + 1, n, k, current, result);
            current.remove(current.size() - 1);
        }
    }

    public static void main(String[] args) {
        System.out.println(combine(4, 2));
        System.out.println(combine(1, 1));
    }
}
