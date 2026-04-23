import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class combinationSum {

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), result);
        return result;
    }

    private static void backtrack(int[] candidates, int remain, int start, List<Integer> current, List<List<Integer>> result) {
        if (remain == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            int value = candidates[i];
            if (value > remain) {
                break;
            }

            current.add(value);
            backtrack(candidates, remain - value, i, current, result);
            current.remove(current.size() - 1);
        }
    }

    public static void main(String[] args) {
        System.out.println(combinationSum(new int[] {2, 3, 6, 7}, 7));
        System.out.println(combinationSum(new int[] {2, 3, 5}, 8));
        System.out.println(combinationSum(new int[] {2}, 1));
    }
}
