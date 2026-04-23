import java.util.ArrayList;
import java.util.List;

public class SummaryRanges {

    public static List<String> summaryRanges(int[] nums) {
        List<String> out = new ArrayList<>();
        int i = 0, n = nums.length;
        while (i < n) {
            int start = nums[i];
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) i++;
            if (start == nums[i]) out.add(String.valueOf(start));
            else out.add(start + "->" + nums[i]);
            i++;
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println(summaryRanges(new int[]{0, 1, 2, 4, 5, 7}));    // [0->2, 4->5, 7]
        System.out.println(summaryRanges(new int[]{0, 2, 3, 4, 6, 8, 9})); // [0, 2->4, 6, 8->9]
        System.out.println(summaryRanges(new int[]{}));                    // []
    }
}
