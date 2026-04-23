import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class mergeIntervals {

    public static int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][0];
        }

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> merged = new ArrayList<>();

        int[] current = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            int[] next = intervals[i];

            if (next[0] <= current[1]) {
                current[1] = Math.max(current[1], next[1]);
            } else {
                merged.add(current);
                current = next;
            }
        }

        merged.add(current);
        return merged.toArray(new int[merged.size()][]);
    }

    private static void print(int[][] intervals) {
        for (int[] interval : intervals) {
            System.out.println(Arrays.toString(interval));
        }
    }

    public static void main(String[] args) {
        int[][] a = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        int[][] b = {{1, 4}, {4, 5}};

        print(merge(a));
        System.out.println();
        print(merge(b));
    }
}
